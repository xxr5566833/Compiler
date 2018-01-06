#include"Compiler.h"
//���ֻ����飬ͬʱά���������������Ϣ��ͬʱ��outData���ϵ�ÿ��Ԫ�س�ʼ���ÿռ�
void Compiler::divideToBlock()
{
	//��һ���������������
	int funcnum = 0;
	for(int i = 0 ; i < this->midindex ;i++)
	{
		midcode *code = this->codes[i];
		switch(code->op)
		{
			//������ʼ����(call����תĿ��)/��ţ���ת��Ŀ�꣬��ʵ������Ҳ��һ����ţ�����������init �����������ˣ���Ϊ������
		case LABOP:
		case PRINTFOP:
		case REALPARAOP:
			if(!this->blockBeginFlag[i])
			{
				//��ʼ�����ݽṹ
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i;
				this->blockBeginFlag[i] = true;
			}
			break;
		case EXITOP:
			if(!this->blockBeginFlag[i])
			{
				//��ʼ�����ݽṹ
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i;
				this->blockBeginFlag[i] = true;
			}
			break;

		//call����һ����ret�ķ��ص�ַ/��֧������һ��Ҳ��ͬ��
		case CALLOP:
		case GOTOOP:
		case EQUOP:
		case NEQUOP:
		case LESSOP:
		case MOREOP:
		case LESSEQUOP:
		case MOREEQUOP:
			//������Ԫ�ظ�ֵ��Ȼ���Բ���dagͼ�Ĺ���������������Ҫ��Ϊ
			if(!this->blockBeginFlag[i + 1])
			{
				//��ʼ�����ݽṹ
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i + 1;
				this->blockBeginFlag[i + 1] = true;
			}
			break;
		case RETOP:
			if(!this->blockBeginFlag[i + 1])
			{
				//��ʼ�����ݽṹ
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i + 1;
				this->blockBeginFlag[i + 1] = true;
			}
			break;
		//�����init ������ ����ô�Ͷ��Գ�Ϊһ�������飬�������Լ�Ҫ��Ϊ��ʼ��������һ��ҲҪ��Ϊ��ʼ����ʾһ�������Ŀ�ʼ
		case FUNCBEGINOP:
			//�ڷֿ�ʱ��˳���ÿ���������ڿ�ķ�Χ��ȷ����,������ʼ���ڿ����һ��һ����retop 
			//�����ǰ���Ѿ����ֳ����ˣ���ô��¼blockindex - 1 �����û�б��ֳ��� ����ô��¼blockindex
			this->funcBlockBegin[funcnum++] = this->blockBeginFlag[i] ? this->blockIndex - 1 : this->blockIndex;
			if(!this->blockBeginFlag[i])
			{
				//��ʼ�����ݽṹ
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i;
				this->blockBeginFlag[i] = true;
			}
			if(!this->blockBeginFlag[i + 1])
			{
				//��ʼ�����ݽṹ
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i + 1;
				this->blockBeginFlag[i + 1] = true;
			}
			break;
		}

	}
	this->outData = new bool*[this->blockIndex];
}

void Compiler::findLabel(std::string *label, int *index)
{
	for(int j = 0 ; j < this->blockIndex ; j++)
	{
		int begin = this->blockBegin[j];
		midcode *code = this->codes[begin];
		//labelһ���ǻ�����ĵ�һ�仰����һ��labelһ��ֻ������һ����������
		if(code->op == LABOP)
		{
			if(this->isIdEqual(*(code->rstname), *label))
			{
				//�õ������label��Ӧ�������index
				*index = j;
				//�ҵ��˾Ͳ��ý�������
				break;
			}
		}
	}
}

void Compiler::initBlockConnect()
{
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 >= this->blockIndex ? this->midindex : this->blockBegin[i + 1];


		Block *preblock = this->blockArray[i];
		int preindex = i;
		//������һ����Ԫʽ
		//bug: tnnd ���˰�������ԭ�������� ����ȡ���������һ����Ԫʽ���±�Ӧ����end - 1
		midcode *code = this->codes[end - 1];
		switch(code->op)
		{
			case EQUOP:
			case NEQUOP:
			case LESSOP:
			case MOREOP:
			case LESSEQUOP:
			case MOREEQUOP: 
				{
					//�����������ת���
					//�����������ת����ô���ĺ�̽ڵ�Ӧ����һ���ǵ�ǰ�ڵ�ż�1����Ϊ���һ��һ����exit���������ﲻ����i+1������Χ�����
					preblock->next1 = preindex + 1;
					//ͬʱ��һ���������ǰ��ҲҪ����
					Block *nextblock = this->blockArray[preindex + 1];
					nextblock->prearray[nextblock->prenum ++] = preindex; 

					//Ȼ��������label���֣���ʱ���������ĺ�̽ڵ����������һ�������label��Ӧ�Ŀ�
					std::string *label = code->rstname;
					//������������label��Ӧ�Ŀ�,������Ҫȫ�ּ�飬��Ϊ���ܻ�������
					int branchindex = -1;
					this->findLabel(label, &branchindex);
					preblock->next2 = branchindex;
					nextblock = this->blockArray[branchindex];
					nextblock->prearray[nextblock->prenum ++] = preindex;
				}
				break;
			case GOTOOP:
				{
					std::string *label = code->rstname;
					int nextindex = -1;
					this->findLabel(label, &nextindex);
					//goto������ڿ�ĺ�̽�����һ��
					preblock->next2 = nextindex;
					Block* nextblock = this->blockArray[nextindex];
					nextblock->prearray[nextblock->prenum ++] = preindex;
				}
				break;
			case EXITOP:
				break;
			case RETOP:
			//�˳�Ҳ�����̻�������
			//�������ؾͲ�Ҫ���ú�̻������ˣ�����Ϊret�ĺ�һ�����Ǻ�����ʼ���ţ����Ժ�����ʼ���ڵĻ�����Ҳû��ǰ���ڵ�
				break;
			default:
				{
					//ʣ�µľ�ֱ�Ӱ���һ����������Ϊһ�����
					preblock->next1 = preindex + 1;
					//ͬʱ��һ���������ǰ��ҲҪ����
					Block *nextblock = this->blockArray[preindex + 1];
					nextblock->prearray[nextblock->prenum ++] = preindex; 
				}
		}

	}
}

void Compiler::printBlockConnect()
{
	for(int i = 0 ; i < this->blockIndex ; i ++)
	{
		Block *block = this->blockArray[i];
		std::cout << "������" << i;
		std::cout << "�ĺ�̻�������:" << block->next1 << " " << block->next2 << std::endl;
		std::cout << "ǰ����������:" << std::endl;
		for(int j = 0 ; j < block->prenum ; j++)
		{
			std::cout << block->prearray[j] << " ";
		}
		std::cout << std::endl;
		
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

bool Compiler::canAdd(bool flag[],  Node *x, Node* midqueue[], int length, Node *dag[])
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
	//���ﻹҪ���ϣ����е�ȡ����ֵ�Ľڵ㣬����Ҫ�����нڵ�ű�����ĸ����鸳ֵ�Ľ������м�����Ժ���ܱ�����ڵ�
	//���и����鸳ֵ�Ľ�㣬����Ҫ�����нڵ�ű����������ȡֵ�ڵ㶼�����м���к���ܱ������м����
	if(x->op == LARRAYOP)
	{
		for(int i = 0 ; i < length ; i++)
		{
			//���������м�ڵ�
			Node *midnode = midqueue[i];
			Node *arraynode = dag[midnode->xindex];
			if(midnode->index > x->index && midnode->op == RARRAYOP && this->isIdEqual(*arraynode->mainname, *x->mainname))
			{
				//���index�ȵ�ǰ��index�󣬣���ʾ����ڵ㱾���͸��ڵ�ǰ���֮��ִ�У�����op������ȡֵ�������������һ��
				//��ô����Ҫ����Щ��㶼������󣬲��ܼ��뵱ǰ��㣡
				choose = choose && flag[midnode->index];
			}
		}
	}
	if(x->op == RARRAYOP)
	{
		for(int i = 0 ; i < length ; i++)
		{
			//���������м�ڵ�
			Node *midnode = midqueue[i];
			Node *arraynode = dag[x->xindex];
			if(midnode->index > x->index && midnode->op == LARRAYOP && this->isIdEqual(*arraynode->mainname, *midnode->mainname))
			{
				//���index�ȵ�ǰ��index�󣬣���ʾ����ڵ㱾���͸��ڵ�ǰ���֮��ִ�У�����op�Ǹ����鸳ֵ
				//��ô����Ҫ����Щ��㶼������󣬲��ܼ��뵱ǰ��㣡
				choose = choose && flag[midnode->index];
			}
		}
	}
	return choose;
}


void Compiler::DAG()
{
	//����һ�������������100���ڵ�
	const int kMaxNodeNum = 100;
	this->midindex = 0;
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int blockindex = i;
		int begin = this->blockBegin[i];
		int end = i + 1 >= this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		int tablength = 0;
		int nodeindex = 0;
		ListNode *nodetab[kMaxNodeNum];
		Node *dag[kMaxNodeNum];
		//���ﻹ�ø��ݵ�ǰblockindex�ж����ĸ��������
		int funcref = -1;
		for(int k = 0 ; k < this->funcNum ; k++)
		{
			if(k == this->funcNum - 1)
			{
				funcref = k;
				break;
			}
			else if(this->funcBlockBegin[k] <= blockindex && this->funcBlockBegin[k + 1] > blockindex)
			{
				funcref = k;
				break;
			}
		}
		midcode *firstcode = this->codes[begin];

		//������ĵ�һ�仰��Ҫ����Դ�����Ϊ���������ǲ�ȷ���Ŀ����ǣ���init������۱�Ţ�goto��printf��scanf
		//���˸�ֵ�������������ȫ��ԭ�����
		if(firstcode->op != ADDOP && firstcode->op != SUBOP && firstcode->op != MULOP && firstcode->op != DIVOP)
		{
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, false);
			begin += 1;
		}
		//�����ʱ����������ˣ���ô��ֱ��continue
		if(end == begin)
			continue;
		//�����ʱ����������ֻʣ��һ�仰û�д����ˣ���ôֱ�Ӵ�����ʣ�µ���ת��������exit�����Ǻ�����ʼ��䣬ֱ��continue
		if(end - 1 == begin)
		{
			firstcode = this->codes[begin];
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, false);
			continue;
		}
		//��ʱ������һ��������������Ԫʽ����ôһ��������һ���������
		//���ﲻһ�����еĻ����鶼�ǿ��Ծ���dagͼ�Ż��ģ���������һ�����ƣ�ֻ���ҵ������ӱ��ʽ�ĲŻ�ʹ��dagͼ�����Ż�
		int findcount = 0;
		//������Ϊ���һ�仰��һ���ܲ���dagͼ�Ĵ��������ԣ�������Ҫ�ж�һ�²���dagͼ������˳��
		midcode *endcode = this->codes[end - 1];
		int endindex = 0;
		if(endcode->op == SCANFOP || endcode->op == ADDOP || endcode->op == SUBOP || endcode->op == MULOP
			|| endcode->op == DIVOP || endcode->op == RARRAYOP || endcode->op == LARRAYOP)
		{
			endindex = end;
		}
		else{
			endindex = end - 1;
		}

		for(int j = begin ; j < endindex ; j++)
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
			case LARRAYOP:
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
					//bug:�����������Ϊ�������������ô����ý������Ҳ�������ȣ���ôҲ���ܰ�����м�ڵ���Ϊ����Ԫʽ���м�ڵ�
					//��Ϊ�����������һ������ô�ǲ�����Ϊ�ȼ۵��ӽڵ���ڵ�
					//�ٸ����� a[1] = b  c[1] = b ��ô�������ԭ���Ĳ�����ʽ��a��c����һ���м�ڵ㣬��ʱ�������һ��t = c[1] ��ô���ͻ��a���ڵĽ����Ϊ�����������Ϊ
					//a��c��indexһ���������������Ƕ���LARRAYOP ����Ԫʽ�����ҽ��� �����ʶ��Ҳһ��ʱ������ͬһ���м�ڵ�
					if(!(node->isLeaf) && node->op == code->op && node->xindex == x->index && node->yindex == y->index)
					{

						if(code->op != LARRAYOP)
						{
							mid = node;
							findcount += 1;	
							//���ԣ��������ֿ�ȱʱ�Ÿ�������������
							if(mid->flag)
							{
								*mid->mainname = *code->rstname;
							}
						}
						else{
							if(this->isIdEqual(*code->rstname, *node->mainname))
							{
								//ֻ�е�������һ��ʱ���������ҵ�
								mid = node;
								findcount += 1;	
							}
						}
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
					*mid->mainname = *code->rstname;
					mid->flag = false;
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
					z->index = mid->index;
				}
				else{
					//��ʾ�ڽ������ҵ���z����ô���zԭ����ĳ�����������֣���ô����Ҫ������Ӧ����flag
					Node *node = dag[z->index];
					if(this->isIdEqual(*node->mainname, *z->name))
					{
						node->flag = true;
					}
					z->index = mid->index;
					
				}

				break;
			}
		}
		//�о�dagͼ�Ż������ʱûʲô�á���
		//�����侫�����ڡ����������ʽ��ɾ����������������findcount������ͳ�������������ʽ�Ĵ��������Ϊ0�Σ��Ǿͱ�׷������ˣ�������϶���ԭ��һ��
		if(!findcount)
		{
			for(int j = begin ; j < end ; j++)
			{
				midcode *code = this->codes[j];
				this->pushMidCode(code->op, code->op1name, code->op2name, code->rstname, false);
			}
			continue;
		}
		std::cout << "��" << i << "�����Ż�" << std::endl;
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
			//������ôӺ���ǰ�ң������Ϳ��Ա�֤�ȼ��뵽�����е��Ǻ���ֵı��ʽ
			for(int j = midlength - 1 ; j >= 0 ; j--)
			{
				Node *node = midqueue[j];
				if(this->canAdd(flag, node, midqueue, midlength, dag))
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
				if(this->canAdd(flag, child, midqueue, midlength, dag))
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
		/*����м�ڵ���е��������������Ҫ�ļ���˳�����ﻹ��Ҫ�����Ż�ǰ�м�
		  ������Ż����м����֮���ӳ���ϵ�������ԣ���ʱ�����ĸ������ܻ���٣����������ȡ��ӳ�䷽���ǣ���������ʱ������֮��Ļ����黹��Ծ����ô����ɾ�������
		  ����Ծ����ô�Ϳ���ɾ��
		  �������Ǳ����м�ڵ�������ÿһ��
		*/
		for(int j = queuelength - 1 ; j >= 0 ; j--)
		{
			Node *midnode = queue[j];
			std::string *mid = new std::string();
			//�����޸ģ���һ���������ֵ�,��������һ���ᱻ����������

			*mid = *midnode->mainname;
			Node *x = dag[midnode->xindex];
			Node *y = dag[midnode->yindex];
			std::string *op1name = new std::string();
			std::string *op2name = new std::string();
			//�ı�Ϊ��������Ҷ�ӽڵ㻹���м�ڵ㣬��ѡ��������������Ϊ������
			*op1name = *x->mainname;
			*op2name = *y->mainname;
			

			//��ʱ�Ϳ��������µ��м����
			this->pushMidCode(midnode->op, op1name, op2name, mid, false);
			//ͬʱ��ʱ����Ҫ�Ѻ�����ڵ��index��ͬ�� ��ʶ�� #RET ��ʱ���� ��������Ӧ�ĸ�ֵ������������ʱ��������Ҫ����������Ծ����������������out��������û����
			for(int k = 0 ; k < tablength ; k++)
			{
				ListNode *listnode = nodetab[k];
				if(listnode->index == midnode->index && !this->isIdEqual(*listnode->name, *mid))
				{
					//��ֵ��䣬�����õ�ǰ�м�ڵ��ֵ�� ������ڵ�index��ͬ�ı���
					//�������ʱ�������߾ֲ���ʶ������Ҫ�ж�out����
					if(this->isOperandTemp(listnode->name))
					{
						//���Ȼ�����ڷ��ű��е�index
						int index = -1;
						this->getIndexInTab(&index, funcref, listnode->name);
						//�����������ڻ���Ծ����ô��Ҫ����һ����ֵ�������
						if(this->outData[blockindex][index])
						{
							this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
						}
						else{
							/*bug:
							�������Ծ�ˣ���ô��Ҫɾ���������������ע�⣬��Ȼ�Ժ󲻻�Ծ�ˣ�����������������Ժ���ܻ���Ծ
							��������ܻ����õ������ʱ�����������������������Ԫʽ�����˻�Ծ������������ô��һ���ܵõ���ȷ��ֵ���������
							û�в��룬�����������һ�仰������ô������Ҫ�������ɾ�˵Ĳ��������ɵȼ۵�����һ��������
							*/
							//�Ȼ�����һ����Ԫʽ,������һ����Ԫʽ�����漸�֣���ô��Ҫ�滻
							std::cout << *listnode->name << "��ɾȥ" << std::endl;
							midcode *code = this->codes[end - 1];
							switch(code->op)
							{
							case EQUOP:
							case NEQUOP:
							case MOREOP:
							case MOREEQUOP:
							case LESSOP:
							case LESSEQUOP:
								{
									//������������������ǲ�����Ҫ�滻
									if(this->isIdEqual(*(code->op1name), *(listnode->name)))
									{
										//������ڵ��mainname��Ϊ�µĲ�����
										*code->op1name = *mid;
										std::cout << *code->op1name << " ���滻Ϊ�� " << *mid << std::endl;
									}
									if(this->isIdEqual(*code->op2name, *listnode->name))
									{
										*code->op2name = *mid;
										std::cout << *code->op2name << " ���滻Ϊ�� " << *mid << std::endl;
									}
								}
								break;
							}
						}
					}
					//������ʱ��������ô���ж��ǲ��Ǳ�ʶ����Ȼ����Ҫ�ж������ʶ����һ���򵥱�������һ������
					//��һ�����飬һ����Ҫ������Ӧ�Ĳ�����䣬�����������ж��ǲ���һ��ȫ�ֱ����������ȫ�ֱ��������ǽ���������Ծ����ô����Ҫ�в����Եĸ�ֵ���
					//bug:�����һ�����飬��ô����Ҫֱ�Ӳ��ϸ�ֵ���
					else if(this->isOperandId(listnode->name))
					{

							int index = -1;
							this->getIndexInTab(&index, funcref, listnode->name);
							if(index == -1)
							{
								//��һ��ȫ�ֱ�������ô����
								this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
							}
							else{
								//��һ���ֲ���������ô���������Ƿ��Ծ
								if(this->outData[blockindex][index])
								{
									this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
								}
								else{
									//�������Ծ��������Ҫ�ж����һ����Ԫʽ��û���õ������ʶ��
									std::cout << *listnode->name << "��ɾȥ" << std::endl;
								}
							}					
					}
					//Ȼ��ֻ�п�����#RET��
					else
						this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
				}
			}
		}
		//���￴�Ƿ���Ҫ�������һ��
		if(endindex == end - 1)
		{
			midcode *endcode = this->codes[end - 1];
			this->pushMidCode(endcode->op, endcode->op1name, endcode->op2name, endcode->rstname, false);
		}
	}
}

void Compiler::printBlock()
{
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 >= this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		for(int j = begin ; j < end ; j++)
		{
			this->writeMidCode(this->codes[j], this->blockFile);
		}
		this->blockFile << "��" << i << "��������" << std::endl;
	}
}

//��ʼ��
void Compiler::initOptimize()
{
	this->blockIndex = 0;
	this->optimizeMidIndex = 0;
	//��ʼ��flag����ȫΪfalse
	for(int i = 0 ; i < kMaxBasicBlock ; i++)
	{
		this->blockBeginFlag[i] = false;
	}
}

void Compiler:: getIndexInTab(int *index, int funcref, std::string *name)
{
	int maxlength = this->funcSymNum[funcref];
	symbol **symarray = this->funcSymTab[funcref];
	for(int i = 0 ; i < maxlength ; i++)
	{
		symbol *sym = symarray[i];
		if(this->isIdEqual(*sym->name, *name))
		{
			*index = i;
			return ;
		}
	}
}

//��������������ÿһ��������Ϊһ��������
void Compiler:: dataFlowAnalysis()
{

	//��Ȼ���Ժ�����Ϊ������������ô��Ҫ�Ȱ�������
	bool **use = new bool*[this->blockIndex];
	bool **def = new bool*[this->blockIndex];
	bool **in = new bool*[this->blockIndex];
	bool **out = new bool*[this->blockIndex];
	//use def in out ����bool�����ʾ
	for(int i = 0 ; i < this->funcNum ; i++)
	{
		//��ʾ��ǰ�������±�
		int funcref = i;
		//������begin���Ǻ����Ŀ�ʼ��end���Ǻ����Ľ���,���ȱ���һ�飬����ÿ�����use��def����
		int blockbegin = this->funcBlockBegin[i];
		int blockend = i + 1 >= funcNum ? this->blockIndex : this->funcBlockBegin[i + 1];
		int symnum = this->funcSymNum[funcref];
		//���ȳ�ʼ�����е�in / use / def /out ����Ϊfalse
		for(int j = blockend - 1 ; j >= blockbegin ; j--)
		{
			use[j] = new bool[symnum];
			def[j] = new bool[symnum];
			in[j] = new bool[symnum];
			out[j] = new bool[symnum];
		}
		for(int j = blockend - 1 ; j >= blockbegin ; j --)
		{
			//���ȱ���һ�飬���ú�ÿ���������use���Ϻ�def����
			int blockindex = j;
			int begin = this->blockBegin[j];
			int end = j + 1 >= this->blockIndex ? this->midindex : this->blockBegin[j + 1];
			


			for(int k = 0 ; k < symnum ; k++)
			{
				in[j][k] = false;
				use[j][k] = false;
				def[j][k] = false;
				out[j][k] = false;
			}
			//use / def ���ϵ�ȷ��
			for(int k = begin ; k < end ; k++)
			{
				midcode *code = this->codes[k];
				switch(code->op)
				{
				case FUNCBEGINOP:
					{
						
					}
					break;
				case ADDOP:
				case SUBOP:
				case MULOP:
				case DIVOP:
					{
						//��������������㣬��ô�����������use���Ϻ�def����
						std::string *op1name = code->op1name;
						std::string *op2name = code->op2name;
						std::string *rstname = code->rstname;
						if(this->isOperandId(op1name) || this->isOperandTemp(op1name))
						{
							//���������1��һ����ʶ����������ʱ������Ҳֻ�������ֱ����������
							//���Ȼ�������±�
							int index = -1;
							this->getIndexInTab(&index, funcref, op1name);
							//���û���ҵ�����ô˵����һ��ȫ�ֵı�������Ϊû���ھֲ��ĺ��������ҵ���,����ȫ�ֱ������ǲ�������������������������Ҫ���ж�index
							//���def������û������˵����֮ǰ��û�б�def����ô�Ϳ�����use�����������
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
						if(this->isOperandId(op2name) || this->isOperandTemp(op2name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op2name);
							//���def������û������˵����֮ǰ��û�б�def����ô�Ϳ�����use�����������
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}

						}
						//��������������һ���򵥱�����ʶ��������һ����ʱ����
						if(this->isOperandId(rstname) || this->isOperandTemp(rstname))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, rstname);
							//���use������û������˵����֮ǰû�б�use����ô��ʱ��def�����������
							if(index != -1 && !use[blockindex][index])
							{
								def[blockindex][index] = true;
							}
						}
					}
					break;
				case REALPARAOP:
					{
						std::string *rstname = code->rstname;
						if(this->isOperandId(rstname) || this->isOperandTemp(rstname))
						{
							//push ��ʶ�� ��ʾʹ�������ʶ��
							int index = -1;
							this->getIndexInTab(&index, funcref, rstname);
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
					}
					break;
				case RARRAYOP:
					{
						std::string *op2name = code->op2name;
						std::string *rstname = code->rstname;
						if(this->isOperandId(op2name) || this->isOperandTemp(op2name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op2name);
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
						if(this->isOperandTemp(rstname))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, rstname);
							//��ʱ����һ���ں����������Ͳ��ж���
							if(!use[blockindex][index])
							{
								def[blockindex][index] = true;
							}
						}
					}
					break;
				case EQUOP:
				case NEQUOP:
				case MOREOP:
				case MOREEQUOP:
				case LESSOP:
				case LESSEQUOP:
					{
						//��ת���Ҳ��Ҫ��ʹ�����
						std::string *op1name = code->op1name;
						std::string *op2name = code->op2name;
						if(this->isOperandId(op1name) || this->isOperandTemp(op1name))
						{
							//���������1��һ����ʶ����������ʱ������Ҳֻ�������ֱ����������
							//���Ȼ�������±�
							int index = -1;
							this->getIndexInTab(&index, funcref, op1name);
							//���def������û������˵����֮ǰ��û�б�def����ô�Ϳ�����use�����������
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
						if(this->isOperandId(op2name) || this->isOperandTemp(op2name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op2name);
							//���def������û������˵����֮ǰ��û�б�def����ô�Ϳ�����use�����������
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}

						}
					}
					break;
				case SCANFOP:
					{
						std::string *rstname = code->rstname;
						int index = -1;
						this->getIndexInTab(&index, funcref, rstname);
						//scanf һ����һ����ʶ������ô��Ҫ�ж�����ȫ�ֱ������Ǿֲ�����
						if(index != -1 && !use[blockindex][index])
						{
							def[blockindex][index] = true;
						}
					}
					break;
				case PRINTFOP:
					{
						std::string *rstname = code->rstname;
						if(this->isOperandTemp(rstname))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, rstname);
							if(!def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
					}
					break;
				case LARRAYOP:
					{
						std::string *op1name = code->op1name;
						std::string *op2name = code->op2name;
						if(this->isOperandId(op1name) || this->isOperandTemp(op1name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op1name);
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
						if(this->isOperandId(op2name) || this->isOperandTemp(op2name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op2name);
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
					}
					break;
				}
			}

		}
		//����in/out���ϵļ���
		bool flag = true;
		while(flag)
		{
			//flag ��ʾ�Ƿ���Ҫ���¼��㣬һ��in�и��£���ôflag������Ϊtrue��ʾ��Ҫ����һ��
			flag = false;
			for(int j = blockend - 1 ; j >= blockbegin ; j --)
			{
				int blockindex = j;
				int symnum = this->funcSymNum[funcref];
				Block *block = this->blockArray[blockindex];
				//���ȼ���out[blockindex]����Ϊ��̿����������
				int next1 = block->next1;
				int next2 = block->next2;
				if(next1 != -1)
				{
					if(next2 != -1)
					{
						//��ô��������������������in���ϵĲ�
						for(int k = 0 ; k < symnum ; k++)
						{
							out[blockindex][k] = in[next1][k] || in[next2][k];
						}
					}
					else{
						//������ǻ�����1��in����
						for(int k = 0 ; k < symnum ; k++)
						{
							out[blockindex][k] = in[next1][k];
						}
					}
				}
				else{
					if(next2 != -1)
					{
						//��ô������ǻ�����2��in����
						for(int k = 0 ; k < symnum ; k++)
						{
							out[blockindex][k] = in[next2][k];
						}
					}
					else{
						//������������Բ�����
					}
				}
				//Ȼ����ݹ�ʽ����in����,ע���ʱ��Ҫ�ж�in�����Ƿ񱻸ı�


				for(int k = 0 ; k < symnum ; k++)
				{
					bool result = use[blockindex][k] || (out[blockindex][k] && (! def[blockindex][k]));
					if(result != in[blockindex][k])
					{
						//��������һ������ô��Ҫ����flagΪtrue
						flag = true;
						in[blockindex][k] = result;
					}
				}
				
			}
		}
		//������Ͱ����������in/out���ϸ������
		//�������һ�½��
		for(int j = blockend - 1 ; j >= blockbegin ; j --)
		{
			int blockindex = j;
			std::cout << "��" << blockindex << "�������飺" << std::endl;
			symbol **symtab = this->funcSymTab[funcref];
			std::cout << "use�����У�" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(use[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			std::cout << "def�����У�" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(def[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			std::cout << "out�����У�" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(out[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			std::cout << "in�����У�" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(in[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			this->outData[blockindex] = new bool[symnum];
			//��out���ϼ�¼����
			for(int k = 0 ; k < symnum ; k++)
			{
				this->outData[blockindex][k] = out[blockindex][k];
			}
		}
		std::cout << "��Ծ�����������" << std::endl;


		//��ʼ������ͻͼ����ÿ���ֲ�����ʱ�����ͼ򵥱��������������ǵļĴ���
		//Ŀǰ���壺�����Ļ�Ծ��Χ���Ի�����Ϊ��λ��1.�û������def�����������������ô����������иñ�����Ծ2.�û������in��������������������������
		//�иñ�����Ծ
		//������ͻ������������Ļ�Ծ��Χ�н�������ô���г�ͻ

		//������Ҫ�ѿ��Է���Ĵ����ĸ���ȡ��������Ϊ��ͻͼֻ��Ҫ������Щ�������������鲻��Ҫ����
		int nodenum = 0;
		int node2sym[1000];
		for(int j = 0 ; j < symnum ; j++)
		{
			symbol *sym = this->funcSymTab[funcref][j];
			if(sym->symbolType == SIMPLESYM || sym->symbolType == PARASYM)
			{
				node2sym[nodenum ++] = j;
			}
		}
		//�����ͰѲ����ͻͼ�����ı�������ȡ������,�����Ȳ������������û�п�Խ������
		//ֻҪ����һ���ֲ�����ʱ���������Ǽ򵥱��������ǲ�����������ô���Ϳ��Ա�����Ĵ���


		ConflictNode **nodearray = new ConflictNode*[nodenum];
		for(int j = 0 ; j < nodenum ; j++)
		{
			ConflictNode *node = new ConflictNode();
			//bug:����û�а������new�Ľ��ŵ�nodearray������
			nodearray[j] = node;
			node->edgenum = 0;
			for(int k = 0 ; k < nodenum ; k++)
			{
				node->connect[k] = false;
			}
		}
		for(int j = 0 ; j < nodenum ; j++)
		{
			ConflictNode *node1 = nodearray[j];
			int symindex1 = node2sym[j];
			for(int k = j + 1 ; k < nodenum ; k++)
			{
				//�ж����������Ļ�Ծ��Χ�Ƿ��н���
				ConflictNode *node2 = nodearray[k];
				int symindex2 = node2sym[k];
				int flag = false;
				for(int l = blockend - 1 ; l >= blockbegin ; l--)
				{
					bool jflag = in[l][symindex1];
					bool kflag = in[l][symindex2];
					jflag = jflag || def[l][symindex1];
					kflag = kflag || def[l][symindex2];
					if(jflag && kflag)
					{
						//�ܽ��������֧��˵��jflag��kflag����true,������������֮���ͻ
						flag = true;
						break;
					}
				}
				if(flag)
				{
					//˵�����г�ͻ�ģ���ô������Ӧ�ĳ�ͻ,ע�������ڵ㶼Ҫ���ú�
					node1->connect[k] = true;
					node1->edgenum ++;
					node2->connect[j] = true;
					node2->edgenum ++;
				}
			}
		}
		//��ͻͼ������ϣ����������������ͻͼ�����㷨����Ĵ����������ݶ����üĴ�����14��
		int *order = new int[nodenum];
		int orderindex = 0;
		//��¼��Щ��㲻������Ĵ�����Ϊfalse��ʾ����Ĵ�����Ϊtrue��ʾ��������Ĵ���
		bool *noallocflag = new bool[nodenum];
		//��¼��Щ�ڵ㱻������
		bool *outflag = new bool[nodenum];
		for(int j = 0 ; j < nodenum ; j++)
		{
			noallocflag[j] = false;
			outflag[j] = false;
		}

		while(orderindex < nodenum)
		{
			//�����־λ��¼���Ƿ��ҵ���һ�����ӱ���С��K�Ľ�㣬����ҵ��ˣ���ôֱ��continue��û�ҵ�����ô��ѡһ���ڵ��ʶΪ������ȫ�ּĴ����Ľ��
			bool continueflag = false;
			//���ȱ������ҵ�һ�����ӱ���С��K�Ľ��
			for(int j = 0 ; j < nodenum ; j++)
			{
				ConflictNode *node = nodearray[j];
				if(!outflag[j] && node->edgenum < kMaxRegAvailable)
				{
					continueflag = true;
					order[orderindex ++] = j;
					//��������ͼG�����ߣ�������Ȼ���ߣ����ǽڵ�֮ǰ������״̬ҲҪ��¼�������������������Ӧ��edgenum����
					outflag[j] = true;
					//���ٺ��������Ľ���edgenum
					for(int k = 0 ; k < nodenum ; k++)
					{
						ConflictNode *temp = nodearray[k];
						if(temp->connect[j])
						{
							temp->edgenum --;
						}
					}
					break;
				}
			}
			if(!continueflag)
			{
				//ѡ��һ���ʵ��Ľ�㣬��ʶΪ������ȫ�ּĴ����Ľ�㣬
				//����ѡ���Ǹ����ӱ������Ľ�㣬��ʱ���еĽ������ӱ���һ�������ڵ���K
				int maxedgenumindex = -1;
				int maxedgenum = -1;
				for(int j = 0 ; j < nodenum ; j++)
				{
					if(!outflag[j])
					{
						ConflictNode *node = nodearray[j];
						if(node->edgenum >= maxedgenum)
						{
							maxedgenumindex = j;
							maxedgenum = node->edgenum;
						}
					}
				}
				//�������ҵ������ӱ������Ľ�㣬���������ǰ�����ʶΪ������ȫ�ּĴ����Ľ�㣬����ͼ������
				outflag[maxedgenumindex] = true;
				noallocflag[maxedgenumindex] = true;
				order[orderindex ++] = maxedgenumindex;
				//���߾͸�������������edgenum
				for(int k = 0 ; k < nodenum ; k++)
				{
					ConflictNode *temp = nodearray[k];
					if(temp->connect[maxedgenumindex])
					{
						temp->edgenum --;
					}
				}
			}
		}

		//ok����������Ĳ��裬�Ͱѽ���˳��������ˣ��������Ϳ�ʼ���ձ����ߵĴ����������
		//��¼�Ƿ��Ѿ������뵽ͼ��
		bool *isadd = new bool[nodenum];
		//��¼�Ĵ����ķ������
		int *regalloc = new int[nodenum];
		for(int j = 0 ; j < nodenum ; j++)
		{
			isadd[j] = false;
		}
		for(int j = nodenum - 1 ; j >= 0 ; j--)
		{
			int nodeindex = order[j];
			ConflictNode *node = nodearray[nodeindex];
			isadd[nodeindex] = true;
			//���ﰴ������ڵ��Ƿ񱻱��Ϊ������ȫ�ּĴ�������
			if(noallocflag[nodeindex])
			{
				//������ȫ�ּĴ�������ôֱ�Ӱ�������ͼ�м���
				//����ʲô���������Ϳ�����
			}
			else{
				//ͨ�����������������Ѿ������뵽���ͼ�еĽ��ķ���������������ķ���
				//��¼�˼Ĵ������������Ϊfalse��ʾ���ܱ�����Ϊ����Ĵ���
				bool ableflag[kMaxRegAvailable];
				for(int k = 0 ; k < kMaxRegAvailable ; k++)
				{
					ableflag[k] = true;
				}
				for(int k = 0 ; k < nodenum ; k++)
				{
					//���������������������ڵ��Ѿ���������ͼ��������������ڵ㲻��һ��δ����Ĵ�����
					if(node->connect[k] && isadd[k] && !noallocflag[k])
					{
						//�õ����ļĴ������
						int banregindex = regalloc[k];
						//������Ĵ���ban��
						ableflag[banregindex] = false;
					}
				}
				//����Ѳ����õļĴ�����ban���ˣ����������ҵ���һ�������õļĴ�����Ϊ����ڵ��Ӧ�ļĴ���
				for(int k = 0 ; k < kMaxRegAvailable ; k++)
				{
					if(ableflag[k])
					{
						//�ҵ��˵�һ��
						regalloc[nodeindex] = k;
						//����������ʱ������Ӧ�ļĴ�����Ÿ��ǵ���Ӧ�ķ��ű������������Ŀ�����ʱʹ��
						int symindex = node2sym[nodeindex];
						symbol *sym = this->funcSymTab[funcref][symindex];
						sym->regIndex = k;
						break;
					}
				}
			}
		}
		//���������ͷ�����Ͽ���

		//�������һ�·������
		for(int j = 0 ; j < symnum ; j++)
		{
			symbol *sym = this->funcSymTab[funcref][j];
			std::cout << *sym->name << " �������� " << sym->regIndex << " �żĴ���" << std::endl;
		}

		//�ͷſռ�
		delete[] regalloc;
		delete[] isadd;
		delete[] outflag;
		delete[] order;
		delete[] noallocflag;
		for(int j = 0 ; j < nodenum ; j++)
		{
			delete nodearray[j];
		}
		delete[] nodearray;
		for(int j = blockend - 1 ; j >= blockbegin ; j--)
		{
			delete[] use[j];
			delete[] def[j];
			delete[] in[j];
			delete[] out[j];
		}
	}
	delete[] use;
	delete[] def;
	delete[] in;
	delete[] out;
}



//�����Ż�
void Compiler::smallOptimize()
{
	//���������codes��
	int index = this->midindex;
	this->midindex = 0;
	//�����еļ�0����ȥ������Ҫ������������һ����������0����һ����������Ŀ���������ͬ���Ǽӷ�
	//���߼���ʱ���������ͽ��һ����������0
	for(int i = 0 ; i < index ; i++)
	{
		midcode *code = this->codes[i];
		std::string *op1name = code->op1name;
		std::string *op2name = code->op2name;
		std::string *rstname = code->rstname;
		switch(code->op)
		{
		case ADDOP:
			if((this->isIdEqual(*op1name, std::string("0")) && this->isIdEqual(*op2name, *rstname)) || 
				(this->isIdEqual(*op2name, std::string("0")) && this->isIdEqual(*op1name, *rstname)))
			{
				this->writeMidCode(code);
				std::cout << "��ɾ��" << std::endl << std::endl;
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
				
				this->writeMidCode(code);
				std::cout << "��ɾ��" << std::endl << std::endl;
			}
			break;
		case LABOP:
			//�Ż�������label��䣬�����label���������label���滻Ϊ���label
			{
				std::string *result = code->rstname;
				//���Ȱ����lab��䱣������
				this->codes[this->midindex++] = code;
				//��Ϊ������һЩlab��䣬����ѭ����һ�ο��ܲ��Ǵ���һ����ʼ��nexti��¼��iӦΪʲôֵ
				for(int j = i + 1 ; j < index ; j++)
				{

					midcode *labcode = this->codes[j];
					if(labcode->op != LABOP)
					{
						//��������˲���lab���������ôֱ��break
						break;
					}
					else{
						//���������������lab����ô���������lab���滻Ϊresult
						i ++;
						std::string *lab = labcode->rstname;
						for(int k = 0 ; k < index ; k++)
						{
							midcode *replacecode = this->codes[k];
							//��lab���������ô���֣�����labop����Ϊ����Ҫ�������������ľ� goto ��Щbranch ���������
							//bug:����һ��ʼ��Ȼд����EQU NEQU LESS LESSEQU �ȵ� ����
							if((replacecode->op == GOTOOP || replacecode->op == EQUOP || replacecode->op == NEQUOP || replacecode->op == LESSOP || replacecode->op == LESSEQUOP || replacecode->op == MOREOP
								|| replacecode->op == MOREEQUOP) && this->isIdEqual(*replacecode->rstname, *lab))
							{
								this->writeMidCode(replacecode);
								std::cout << "���滻Ϊ:" << std::endl;
								*replacecode->rstname = *result;
								this->writeMidCode(replacecode);
								std::cout << std::endl;
							}
						}
					}
				}
			}
			break;
		case GOTOOP:
			//��������goto����ô��һ��goto����ȡ����
			{
				midcode *deletecode = this->codes[i + 1];
				if(deletecode->op == GOTOOP)
				{
					//���Ȱѵ�ǰ��code�����
					this->codes[this->midindex ++] = code;
					//��һ��Ҳ��goto����ôȡ�����goto,i++ ����
					this->writeMidCode(deletecode);
					std::cout << "��ɾ��" << std::endl << std::endl;;
					i ++;
				}
				else{
					//����ǵð�code�������ˣ�
					this->codes[this->midindex ++] = code;
				}
			}
			break;
		default:
			this->codes[this->midindex++] = code;
		}
	}
	//����ڶ����������ɾ�� goto label ��labbel �������ֵ����
	index = this->midindex;
	this->midindex = 0;
	for(int i = 0 ; i < index ; i++)
	{
		midcode *code = this->codes[i];
		std::string *op1name = code->op1name;
		std::string *op2name = code->op2name;
		std::string *rstname = code->rstname;
		switch(code->op)
		{
			//��Ҫɾ�� goto label�ͺ�һ��label��һ���������ע���ʱҪ�������Ǻ�һ���lab������ǰһ���goto
			//��Ҫע�⣬�����һ�䲻����ɾ���������ô���goto�������Ҫ����������
		case GOTOOP:
			{
				midcode *nextcode = this->codes[i + 1];
				if(nextcode->op == LABOP && this->isIdEqual(*nextcode->rstname, *code->rstname)){
					//��ʱ���������code���ɣ�ע�Ᵽ���һ���label
					this->writeMidCode(code);
					
					std::cout << "��ɾ��" << std::endl << std::endl;
					this->codes[this->midindex++] = nextcode;
					i++;
				}
				else{
					this->codes[this->midindex++] = code;
				}
			}
			break;
		default:
			this->codes[this->midindex++] = code;
		}
	}
}