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
		case PRINTFOP:
		case REALPARAOP:
			this->blockBegin[this->blockIndex++] = i;
			break;
		case EXITOP:
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
	this->divideToBlock();
	const int kMaxNodeNum = 100;
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 >= this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		if(begin == end)
		{
			//���������Ϊ�գ�ֱ������
			continue;
		}
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
		//�����ʱ����������ˣ���ô��ֱ��continue
		if(end == begin)
			continue;
		//�����ʱ����������ֻʣ��һ�仰û�д����ˣ���ôֱ�Ӵ�����ʣ�µ���ת��䣬ֱ��continue
		if(end - 1 == begin)
		{
			firstcode = this->codes[begin];
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, true);
			continue;
		}
		//��ʱ������һ��������������Ԫʽ����ôһ��������һ���������
		//���ﲻһ�����еĻ����鶼�ǿ��Ծ���dagͼ�Ż��ģ���������һ�����ƣ�ֻ���ҵ������ӱ��ʽ�ĲŻ�ʹ��dagͼ�����Ż�
		int findcount = 0;
		//����������dagͼ�Ĺ���,ע���������һ��϶��ǲ�����dagͼ�Ĵ����ģ������
		for(int j = begin ; j < end - 1 ; j++)
		{
			midcode *code = this->codes[j];
			switch(code->op)
			{

			case SCANFOP:
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
					newx->mainname = 0;
					newx->index = nodeindex;
					newx->mainname = new std::string();
					*newx->mainname = *code->op1name;
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
					newy->mainname = 0;
					newy->parentnum = 0;
					newy->xindex = -1;
					newy->yindex = -1;
					newy->index = nodeindex;
					newy->mainname = new std::string();
					*newy->mainname = *code->op2name;
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
						findcount += 1;
						break;
					}
				}
				if(!mid)
				{
					//�������м�ڵ�δ������
					//bug:����һ��ʼû�ж�mid��ֵ
					mid = new Node();
					mid->index = nodeindex;
					mid->isLeaf = false;
					mid->mainname = new std::string();
					mid->mainname = code->rstname;
					mid->op = code->op;
					mid->parentnum = 0;
					mid->xindex = x->index;
					mid->yindex = y->index;
					Node *xnode = dag[x->index];
					Node *ynode = dag[y->index];
					xnode->parentindex[xnode->parentnum ++] = nodeindex;
					ynode->parentindex[ynode->parentnum ++] = nodeindex;
					dag[nodeindex ++] = mid;
				}
				//Ȼ���ڽڵ������z
				ListNode *z = 0;
				this->findNodeInTab(nodetab, tablength, code->rstname, &z);
				if(!z)
				{
					//û���ҵ�
					z = new ListNode();
					z->name = code->rstname;
					//bug:����һ��ʼû�а�z��ӵ�nodetab��
					nodetab[tablength ++] = z;
				}
				//�޸�Ϊ����ʱ��ָ���������֣������ڻָ�ʱһ�������Դ�����ʱ��������Ϊ������
				z->index = mid->index;

				break;
			}
		}
		//�о�dagͼ�Ż������ʱûʲô�á���
		//�����侫�����ڡ����������ʽ��ɾ����������������findcount������ͳ�������������ʽ�Ĵ��������Ϊ0�Σ��Ǿͱ�׷������ˣ�������϶���ԭ��һ��
		if(findcount)
		{
			for(int j = begin ; j < end ; j++)
			{
				midcode *code = this->codes[j];
				this->pushMidCode(code->op, code->op1name, code->op2name, code->rstname, true);
			}
			continue;
		}
		//������dagͼ�ͽڵ���Ժ󣬾Ϳ��Ե����µ��м������
		Node *queue[kMaxNodeNum] = {0};
		int queuelength = 0;
		Node *midqueue[kMaxNodeNum] = {0};
		bool flag[kMaxNodeNum] = {0};
		int midlength = 0;
		//���Ȱ������м�ڵ�������
		for(int j = 0 ; j < nodeindex ; j++)
		{
			Node *node = dag[j];
			if(!node->isLeaf)
			{
				midqueue[midlength ++] = node;
			}
		}
		//Ȼ���������ʽ�㷨���м���
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
			//�����޸ģ���һ���������ֵ�

			//����Ѿ��� �����֣���ô����ֱ������������֣������û�������֣� ��ô����ѡ�������ڵ���ͬ��index ��һ��������Ϊ������
			/*if(!midnode->mainname)
			{
				//û�������֣���һ����Ϊ������
				for(int k = 0 ; k < tablength ; k++)
				{
					ListNode *node = nodetab[k];
					if(node->index == midnode->index)
					{
						midnode->mainname = new std::string();
						*midnode->mainname = *node->name;
						break;
					}
				}
			}*/
			*mid = *midnode->mainname;
			Node *x = dag[midnode->xindex];
			Node *y = dag[midnode->yindex];
			std::string *op1name = new std::string();
			std::string *op2name = new std::string();
			//�ı�Ϊ��������Ҷ�ӽڵ㻹���м�ڵ㣬��ѡ��������������Ϊ������
			*op1name = *x->mainname;
			*op2name = *y->mainname;
			

			//��ʱ�Ϳ��������µ��м����
			this->pushMidCode(midnode->op, op1name, op2name, mid, true);
			//ͬʱ��ʱ����Ҫ�Ѻ�����ڵ��index��ͬ�� ��ʶ�� #RET ��ʱ���� ��������Ӧ�ĸ�ֵ��������Ϊ�޷��ж�֮����Щ�����Ƿ񻹻�Ծ
			for(int k = 0 ; k < tablength ; k++)
			{
				ListNode *listnode = nodetab[k];
				if(listnode->index == midnode->index && !this->isIdEqual(*listnode->name, *mid))
				{
					//��ֵ��䣬�����õ�ǰ�м�ڵ��ֵ�� ������ڵ�index��ͬ�ı���
					this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, true);
				}
			}
		}
		//���ﴦ�����һ����ת���
		midcode *endcode = this->codes[end - 1];
		this->pushMidCode(endcode->op, endcode->op1name, endcode->op2name, endcode->rstname, true);
	}
}

void Compiler::printBlock()
{
	this->divideToBlock();
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 >= this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		for(int j = begin ; j < end ; j++)
		{
			this->writeMidCode(this->codes[j], false, true, true);
		}
		this->optimizeFile << "��" << i << "��������" << std::endl;
	}
}

//��ʼ��
void Compiler::initOptimize()
{
	this->blockIndex = 0;
	this->optimizeMidIndex = 0;
}
//�����Ż�
void Compiler::smallOptimize()
{
	//���������codes��
	this->midindex = 0;
	//�����еļ�0����ȥ������Ҫ������������һ����������0����һ����������Ŀ���������ͬ���Ǽӷ�
	for(int i = 0 ; i < this->optimizeMidIndex ; i++)
	{
		midcode *code = this->optimizeCodes[i];
		std::string *op1name = code->op1name;
		std::string *op2name = code->op2name;
		std::string *rstname = code->rstname;
		switch(code->op)
		{
		case ADDOP:
			if((this->isIdEqual(*op1name, std::string("0")) && this->isIdEqual(*op2name, *rstname)) || 
				(this->isIdEqual(*op2name, std::string("0")) && this->isIdEqual(*op1name, *rstname)))
			{
				std::cout << "����һ��" << std::endl;
				this->writeMidCode(code, true, false, false);
			}
			else{
				this->codes[this->midindex++] = code;
			}
			break;
		case SUBOP:
			if(!(this->isIdEqual(*op1name, *rstname) && this->isIdEqual(*op2name, std::string("0"))))
			{
				this->codes[this->midindex++] = code;
			}
			else{
				std::cout << "����һ��" << std::endl;
				this->writeMidCode(code, true, false, false);
			}
			break;
		default:
			this->codes[this->midindex++] = code;
		}
	}
}