#include"Compiler.h"
//划分基本块
void Compiler::divideToBlock()
{
	//第一条语句属于入口语句
	for(int i = 0 ; i < this->midindex ;i++)
	{
		midcode *code = this->codes[i];
		switch(code->op)
		{
			//函数开始符号(call的跳转目标)/标号（跳转的目标，其实函数名也是一个标号，但是这里用init 函数名代替了）作为入口语句
		case FUNCBEGINOP:
		case LABOP:
		case SCANFOP:
		case PRINTFOP:
		case REALPARAOP:
			this->blockBegin[this->blockIndex++] = i;
			break;
		//call的下一句是ret的返回地址/分支语句的下一句也是同理
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
		//已经进入队列或者本身是一个叶子节点的话， 那么直接返回false
		return false;
	}
	//下面的都是没有进入队列的
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
	//限制一个基本块最多有100个节点
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
		//基本块的第一句话需要特殊对待，因为它的类型是不确定的可能是：①init②运算③标号④goto⑤printf⑥scanf
		//除了赋值以外的其他类型全部原样输出
		if(firstcode->op != ADDOP && firstcode->op != SUBOP && firstcode->op != MULOP && firstcode->op != DIVOP)
		{
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, true);
			begin += 1;
		}
		//如果此时这个基本块就只剩下一句话没有处理了，那么直接处理这剩下的跳转语句，直接continue
		if(end - 1 == begin)
		{
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, true);
			continue;
		}
		//接下来才是dag图的构建,注意这里最后一句肯定是不参与dag图的创建的，最后处理
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
						//满足条件
						mid = node;
						break;
					}
				}
				if(!mid)
				{
					//如果这个中间节点未被创建
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
				//然后在节点表中找z
				ListNode *z = 0;
				this->findNodeInTab(nodetab, tablength, code->rstname, &z);
				if(!z)
				{
					//没有找到
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
				//已经得到了x的信息
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
				//也已经得到了y的信息
				Node *mid = 0;
				for(int k = 0 ; k < nodeindex ; k++)
				{
					Node *node = dag[k];
					if(!(node->isLeaf) && node->op == code->op && node->xindex == x->index && node->yindex == y->index)
					{
						//满足条件
						mid = node;
						break;
					}
				}
				if(!mid)
				{
					//如果这个中间节点未被创建
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
				//然后在节点表中找z
				ListNode *z = 0;
				this->findNodeInTab(nodetab, tablength, code->rstname, &z);
				if(!z)
				{
					//没有找到
					z = new ListNode();
					z->name = code->rstname;
				}
				z->index = mid->index;

				break;
			}
		}
		//建立好dag图和节点表以后，就可以导出新的中间代码了
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
				//一旦有一个中间节点未进入队列，那么最后endflag就一定是false
				Node *node = midqueue[j];
				endflag = endflag && flag[node->index];
			}
			if(endflag)
				break;
			Node *n = 0;
			//选取一个尚未进入队列，但是其所有父亲节点都已经进入队列的中间节点，或者是选取没有父节点的中间节点
			for(int j = 0 ; j < midlength ; j++)
			{
				Node *node = midqueue[j];
				if(this->canAdd(flag, node))
				{
					//说明这个中间节点可以被添加
					n = node;
					queue[queuelength++] = n;
					flag[n->index] = true;
					//因为上面endflag为false，所以这里一定有符合条件的中间节点
					break;
				}
			}
			//接下来依次访问n的左子节点
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
		//最后中间节点队列的逆序就是我们想要的计算顺序，这里还需要建立优化前中间
		//代码和优化后中间代码之间的映射关系，很明显，临时变量的个数一定会减少，而临时变量也是很重要的，
		//所以我们主要需要建立临时变量的映射和一些重要的补偿性质的赋值语句
		//这里我们遍历中间节点队列里的每一个
		for(int j = queuelength - 1 ; j >= 0 ; j--)
		{
			Node *midnode = queue[j];
			std::string *mid = new std::string();
			//这里我们把和这个节点index相同的临时变量都映射到这个新的临时变量
			
			Node *x = dag[midnode->xindex];
			Node *y = dag[midnode->yindex];
			std::string *op1name = new std::string();
			std::string *op2name = new std::string();
			//这里改变策略，不管是叶子节点还是中间节点，都选择一个和它的index相同的名字即可，反正最后同一个index的不同变量的值一定是一样的，都要写对应的赋值语句
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
						//说明就是这个中间节点,那么对应的临时变量下标的增量就是queuelength -1 再减去当前下标
						index = (queuelength - 1) - k;
						break;
					}
				}
				ss << "$t" << newtemp + index;
				*op1name = ss.str();
			}
			//右子节点同理
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
						//说明就是这个中间节点,那么对应的临时变量下标的增量就是queuelength -1 再减去当前下标
						index = (queuelength - 1) - k;
						break;
					}
				}
				ss << "$t" << newtemp + index;
				*op2name = ss.str();
			}
			//这时就可以生成新的中间代码
			this->pushMidCode(midnode->op, op1name, op2name, mid, true);
			//同时这时还需要把和这个节点的index相同的 标识符 #RET 生成相应的赋值操作
			for(int k = 0 ; k < tablength ; k++)
			{
				ListNode *listnode = nodetab[k];
				if(listnode->index == midnode->index)
				{
					if(this->isOperandTemp(listnode->name))
					{
						int oldtemp = atoi(listnode->name->substr(2).c_str());
						//映射到新的临时变量
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
		//然后处理每个基本块的最后一个四元式，因为这里操作数可能是之前的临时变量，所以需要替换为最新的临时变量
		//不过首先还是要保证有最后一句
		//最后记得把newtemp给更新一下
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
		std::cout << "第" << i << "个基本块" << std::endl;
	}
}

//初始化
void Compiler::initOptimize()
{
	this->blockIndex = 0;
	this->optimizeMidIndex = 0;
	this->temp = 0;
}