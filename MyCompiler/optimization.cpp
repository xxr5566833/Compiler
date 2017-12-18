#include"Compiler.h"
//���ֻ�����
void Compiler::divideToBlock()
{
	//��һ���������������
	for(int i = 0 ; i < this->midindex ;i++)
	{
		midcode *code = this->codes[i];
		switch(code->op)
		{
			//������ʼ����(call����תĿ��)/��ţ���ת��Ŀ�꣬��ʵ������Ҳ��һ����ţ�����������init �����������ˣ���Ϊ������
		case FUNCBEGINOP:
		case LABOP:
		case SCANFOP:
		case PRINTFOP:
		case REALPARAOP:
			this->blockBegin[this->blockIndex++] = i;
			break;
		//call����һ����ret�ķ��ص�ַ/��֧������һ��Ҳ��ͬ��
		case RETOP:
		case CALLOP:
		case GOTOOP:
		case EQUOP:
		case NEQUOP:
		case LESSOP:
		case MOREOP:
		case LESSEQUOP:
		case MOREEQUOP:
			this->blockBegin[this->blockIndex++] = i + 1;
			break;
		}
	}
}

void Compiler::findNodeInTab(ListNode *nodelist[], int length, std::string *name, ListNode **x)
{
	for(int i = 0 ; i < length ; i++)
	{
		ListNode *listnode = nodelist[i];
		if(this->isIdEqual(*(listnode->name), *name))
		{
			*x = listnode;
			return ;
		}
	}
}

bool Compiler::canAdd(bool flag[],  Node *x)
{
	if(flag[x->index] || x->isLeaf)
	{
		//�Ѿ�������л��߱�����һ��Ҷ�ӽڵ�Ļ��� ��ôֱ�ӷ���false
		return false;
	}
	//����Ķ���û�н�����е�
	bool choose = true;
	for(int i = 0 ; i < x->parentnum ; i++)
	{
		int parentindex = x->parentindex[i];
		choose = choose && flag[parentindex];
	}
	return choose;
}

void Compiler::DAG()
{
	//����һ�������������100���ڵ�
	const int kMaxNodeNum = 100;
	this->divideToBlock();
	int newtemp = 0;
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 > this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		int tablength = 0;
		int nodeindex = 0;
		ListNode *nodetab[kMaxNodeNum];
		Node *dag[kMaxNodeNum];
		midcode *firstcode = this->codes[begin];
		//������ĵ�һ�仰��Ҫ����Դ�����Ϊ���������ǲ�ȷ���Ŀ����ǣ���init������۱�Ţ�goto��printf��scanf
		//���˸�ֵ�������������ȫ��ԭ�����
		if(firstcode->op != ADDOP && firstcode->op != SUBOP && firstcode->op != MULOP && firstcode->op != DIVOP)
		{
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, true);
			begin += 1;
		}
		//�����ʱ����������ֻʣ��һ�仰û�д����ˣ���ôֱ�Ӵ�����ʣ�µ���ת��䣬ֱ��continue
		if(end - 1 == begin)
		{
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, true);
			continue;
		}
		//����������dagͼ�Ĺ���,ע���������һ��϶��ǲ�����dagͼ�Ĵ����ģ������
		for(int j = begin ; j < end - 1 ; j++)
		{
			midcode *code = this->codes[j];
			switch(code->op)
			{
			
			/*case ASSIGNOP:
				{
				ListNode *x = 0;
				this->findNodeInTab(nodetab, tablength, code->op1name, &x);
				if(x == 0)
				{
					Node *newx = new Node();
					newx->isLeaf = true;
					newx->index = nodeindex;
					newx->op = NOTOP;
					newx->parentnum = 0;
					newx->yindex = -1;
					newx->xindex = -1;
					dag[nodeindex ++] = newx;
					x = new ListNode();
					x->name = code->op1name;
					x->index = newx->index;
					nodetab[tablength ++] = x;
				}

				Node *mid = 0;
				for(int k = 0 ; k < nodeindex ; k++)
				{
					Node *node = dag[k];
					if(!(node->isLeaf) && node->op == code->op && node->xindex == x->index && node->yindex == y->index)
					{
						//��������
						mid = node;
						break;
					}
				}
				if(!mid)
				{
					//�������м�ڵ�δ������
					Node *newz = new Node();
					newz->index = nodeindex;
					newz->isLeaf = true;
					newz->op = code->op;
					newz->parentnum = 0;
					newz->xindex = x->index;
					newz->yindex = y->index;
					Node *xnode = dag[x->index];
					Node *ynode = dag[y->index];
					xnode->parentindex[xnode->parentnum ++] = nodeindex;
					ynode->parentindex[ynode->parentnum ++] = nodeindex;
					dag[nodeindex ++] = newz;
				}
				//Ȼ���ڽڵ������z
				ListNode *z = 0;
				this->findNodeInTab(nodetab, tablength, code->rstname, &z);
				if(!z)
				{
					//û���ҵ�
					z = new ListNode();
					z->name = code->rstname;
				}
				z->index = mid->index;

				break;*/
			case ADDOP:
			case SUBOP:
			case MULOP:
			case DIVOP:
			case RARRAYOP:
				ListNode *x = 0;

				this->findNodeInTab(nodetab, tablength, code->op1name, &x);
				if(!x)
				{
					Node *newx = new Node();
					newx->isLeaf = true;
					newx->op = NOTOP;
					newx->parentnum = 0;
					newx->xindex = -1;
					newx->yindex = -1;
					newx->index = nodeindex;
					dag[nodeindex ++] = newx;
					x = new ListNode();
					x->name = code->op1name;
					x->index = newx->index;
					nodetab[tablength++] = x;
				}
				//�Ѿ��õ���x����Ϣ
				ListNode *y = 0;
				this->findNodeInTab(nodetab, tablength, code->op2name, &y);
				if(!y)
				{
					Node *newy = new Node();
					newy->isLeaf = true;
					newy->op = NOTOP;
					newy->parentnum = 0;
					newy->xindex = -1;
					newy->yindex = -1;
					newy->index = nodeindex;
					dag[nodeindex++] = newy;
					y = new ListNode();
					y->name = code->op2name;
					y->index = newy->index;
					nodetab[tablength++] = y;
				}
				//Ҳ�Ѿ��õ���y����Ϣ
				Node *mid = 0;
				for(int k = 0 ; k < nodeindex ; k++)
				{
					Node *node = dag[k];
					if(!(node->isLeaf) && node->op == code->op && node->xindex == x->index && node->yindex == y->index)
					{
						//��������
						mid = node;
						break;
					}
				}
				if(!mid)
				{
					//�������м�ڵ�δ������
					Node *newz = new Node();
					newz->index = nodeindex;
					newz->isLeaf = true;
					newz->op = code->op;
					newz->parentnum = 0;
					newz->xindex = x->index;
					newz->yindex = y->index;
					Node *xnode = dag[x->index];
					Node *ynode = dag[y->index];
					xnode->parentindex[xnode->parentnum ++] = nodeindex;
					ynode->parentindex[ynode->parentnum ++] = nodeindex;
					dag[nodeindex ++] = newz;
				}
				//Ȼ���ڽڵ������z
				ListNode *z = 0;
				this->findNodeInTab(nodetab, tablength, code->rstname, &z);
				if(!z)
				{
					//û���ҵ�
					z = new ListNode();
					z->name = code->rstname;
				}
				z->index = mid->index;

				break;
			}
		}
		//������dagͼ�ͽڵ���Ժ󣬾Ϳ��Ե����µ��м������
		Node *queue[kMaxNodeNum] = {0};
		int queuelength = 0;
		Node *midqueue[kMaxNodeNum] = {0};
		bool flag[kMaxNodeNum] = {0};
		int midlength = 0;
		while(1)
		{
			bool endflag = true;
			for(int j = 0 ; j < midlength ; j++)
			{
				//һ����һ���м�ڵ�δ������У���ô���endflag��һ����false
				Node *node = midqueue[j];
				endflag = endflag && flag[node->index];
			}
			if(endflag)
				break;
			Node *n = 0;
			//ѡȡһ����δ������У����������и��׽ڵ㶼�Ѿ�������е��м�ڵ㣬������ѡȡû�и��ڵ���м�ڵ�
			for(int j = 0 ; j < midlength ; j++)
			{
				Node *node = midqueue[j];
				if(this->canAdd(flag, node))
				{
					//˵������м�ڵ���Ա����
					n = node;
					queue[queuelength++] = n;
					flag[n->index] = true;
					//��Ϊ����endflagΪfalse����������һ���з����������м�ڵ�
					break;
				}
			}
			//���������η���n�����ӽڵ�
			while(1)
			{
				Node *child = dag[n->xindex];
				if(this->canAdd(flag, child))
				{
					n = child;
					queue[queuelength++] = n;
					flag[n->index] = true;
				}
				else{
					break;
				}
			}

		}
		//����м�ڵ���е��������������Ҫ�ļ���˳�����ﻹ��Ҫ�����Ż�ǰ�м�
		//������Ż����м����֮���ӳ���ϵ�������ԣ���ʱ�����ĸ���һ������٣�����ʱ����Ҳ�Ǻ���Ҫ�ģ�
		//����������Ҫ��Ҫ������ʱ������ӳ���һЩ��Ҫ�Ĳ������ʵĸ�ֵ���
		//�������Ǳ����м�ڵ�������ÿһ��
		for(int j = queuelength - 1 ; j >= 0 ; j--)
		{
			Node *midnode = queue[j];
			std::string *mid = new std::string();
			//�������ǰѺ�����ڵ�index��ͬ����ʱ������ӳ�䵽����µ���ʱ����
			
			Node *x = dag[midnode->xindex];
			Node *y = dag[midnode->yindex];
			std::string *op1name = new std::string();
			std::string *op2name = new std::string();
			//����ı���ԣ�������Ҷ�ӽڵ㻹���м�ڵ㣬��ѡ��һ��������index��ͬ�����ּ��ɣ��������ͬһ��index�Ĳ�ͬ������ֵһ����һ���ģ���Ҫд��Ӧ�ĸ�ֵ���
			if(x->isLeaf)
			{
				for(int k = 0 ; k < tablength ; k++)
				{
					ListNode *n = nodetab[k];
					if(n->index = x->index )
					{
						*op1name = *(n->name);
						break;
					}
				}
			}
			else{
				std::stringstream ss = std::stringstream();
				int index = -1;
				for(int k = queuelength - 1 ; k >= 0 ; k-- )
				{
					Node *node = queue[k];
					if(node->index == x->index)
					{
						//˵����������м�ڵ�,��ô��Ӧ����ʱ�����±����������queuelength -1 �ټ�ȥ��ǰ�±�
						index = (queuelength - 1) - k;
						break;
					}
				}
				ss << "$t" << newtemp + index;
				*op1name = ss.str();
			}
			//���ӽڵ�ͬ��
			if(y->isLeaf)
			{
				for(int k = 0 ; k < tablength ; k++)
				{
					ListNode *n = nodetab[k];
					if(n->index == y->index && (this->isOperandId(n->name) || this->isOperandNumber(n->name) || this->isOperandRet(n->name)))
					{
						*op2name = *(n->name);
						break;
					}
				}
			}
			else{
				std::stringstream ss = std::stringstream();
				int index = -1;
				for(int k = queuelength - 1 ; k >= 0 ; k-- )
				{
					Node *node = queue[k];
					if(node->index == y->index)
					{
						//˵����������м�ڵ�,��ô��Ӧ����ʱ�����±����������queuelength -1 �ټ�ȥ��ǰ�±�
						index = (queuelength - 1) - k;
						break;
					}
				}
				ss << "$t" << newtemp + index;
				*op2name = ss.str();
			}
			//��ʱ�Ϳ��������µ��м����
			this->pushMidCode(midnode->op, op1name, op2name, mid, true);
			//ͬʱ��ʱ����Ҫ�Ѻ�����ڵ��index��ͬ�� ��ʶ�� #RET ������Ӧ�ĸ�ֵ����
			for(int k = 0 ; k < tablength ; k++)
			{
				ListNode *listnode = nodetab[k];
				if(listnode->index == midnode->index)
				{
					if(this->isOperandTemp(listnode->name))
					{
						int oldtemp = atoi(listnode->name->substr(2).c_str());
						//ӳ�䵽�µ���ʱ����
						this->tempMap[temp] = this->temp - 1;
						continue;
					}
					if(this->isOperandRet(listnode->name) || this->isOperandId(listnode->name))
					{
						this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, true);
					}
					
				}
			}
		}
		//Ȼ����ÿ������������һ����Ԫʽ����Ϊ���������������֮ǰ����ʱ������������Ҫ�滻Ϊ���µ���ʱ����
		//�������Ȼ���Ҫ��֤�����һ��
		//���ǵð�newtemp������һ��
		newtemp = this->temp;
	}
}

void Compiler::printBlock()
{
	this->divideToBlock();
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 > this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		for(int j = begin ; j < end ; j++)
		{
			this->writeMidCode(this->codes[j], true, false, false);
		}
		std::cout << "��" << i << "��������" << std::endl;
	}
}

//��ʼ��
void Compiler::initOptimize()
{
	this->blockIndex = 0;
	this->optimizeMidIndex = 0;
	this->temp = 0;
}