#include"Compiler.h"
//划分基本块，同时维护函数基本块的信息，同时给outData集合的每个元素初始化好空间
void Compiler::divideToBlock()
{
	//第一条语句属于入口语句
	int funcnum = 0;
	for(int i = 0 ; i < this->midindex ;i++)
	{
		midcode *code = this->codes[i];
		switch(code->op)
		{
			//函数开始符号(call的跳转目标)/标号（跳转的目标，其实函数名也是一个标号，但是这里用init 函数名代替了）作为入口语句
		case LABOP:
		case PRINTFOP:
		case REALPARAOP:
			if(!this->blockBeginFlag[i])
			{
				//初始化数据结构
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
				//初始化数据结构
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i;
				this->blockBeginFlag[i] = true;
			}
			break;

		//call的下一句是ret的返回地址/分支语句的下一句也是同理
		case CALLOP:
		case GOTOOP:
		case EQUOP:
		case NEQUOP:
		case LESSOP:
		case MOREOP:
		case LESSEQUOP:
		case MOREEQUOP:
			//给数组元素赋值虽然可以参与dag图的构建，但是它必须要作为
			if(!this->blockBeginFlag[i + 1])
			{
				//初始化数据结构
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
				//初始化数据结构
				Block *newblock = new Block();
				newblock->prenum = 0;
				newblock->next1 = -1;
				newblock->next2 = -1;
				this->blockArray[this->blockIndex] = newblock;
				this->blockBegin[this->blockIndex++] = i + 1;
				this->blockBeginFlag[i + 1] = true;
			}
			break;
		//如果是init 函数名 ，那么就独自成为一个基本块，所以它自己要作为开始，它的下一句也要作为开始，表示一个函数的开始
		case FUNCBEGINOP:
			//在分块时，顺便把每个函数所在块的范围给确定了,函数开始所在块的上一块一定是retop 
			//如果当前块已经被分出来了，那么记录blockindex - 1 ，如果没有被分出来 ，那么记录blockindex
			this->funcBlockBegin[funcnum++] = this->blockBeginFlag[i] ? this->blockIndex - 1 : this->blockIndex;
			if(!this->blockBeginFlag[i])
			{
				//初始化数据结构
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
				//初始化数据结构
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
		//label一定是基本块的第一句话，且一个label一定只存在于一个基本块中
		if(code->op == LABOP)
		{
			if(this->isIdEqual(*(code->rstname), *label))
			{
				//得到了这个label对应基本块的index
				*index = j;
				//找到了就不用接着找了
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
		//获得最后一句四元式
		//bug: tnnd 查了半天问题原来出现在 这里取基本块最后一个四元式，下标应该是end - 1
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
					//如果是条件跳转语句
					//首先如果不跳转，那么它的后继节点应该有一个是当前节点号加1，因为最后一句一定是exit，所以这里不考虑i+1超出范围的情况
					preblock->next1 = preindex + 1;
					//同时下一个基本块的前驱也要设置
					Block *nextblock = this->blockArray[preindex + 1];
					nextblock->prearray[nextblock->prenum ++] = preindex; 

					//然后获得它的label名字，此时这个基本块的后继节点就是它的下一块或者是label对应的块
					std::string *label = code->rstname;
					//接下来获得这个label对应的块,这里需要全局检查，因为可能会跳回来
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
					//goto语句所在块的后继仅仅有一个
					preblock->next2 = nextindex;
					Block* nextblock = this->blockArray[nextindex];
					nextblock->prearray[nextblock->prenum ++] = preindex;
				}
				break;
			case EXITOP:
				break;
			case RETOP:
			//退出也不设后继基本块了
			//函数返回就不要设置后继基本块了，而因为ret的后一句总是函数开始符号，所以函数开始所在的基本块也没有前驱节点
				break;
			default:
				{
					//剩下的就直接把下一个基本块作为一个后继
					preblock->next1 = preindex + 1;
					//同时下一个基本块的前驱也要设置
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
		std::cout << "基本块" << i;
		std::cout << "的后继基本块有:" << block->next1 << " " << block->next2 << std::endl;
		std::cout << "前驱基本块有:" << std::endl;
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
	//这里还要加上，所有的取数组值的节点，必须要在所有节点号比它大的给数组赋值的结点加入中间队列以后才能被加入节点
	//所有给数组赋值的结点，必须要在所有节点号比它大的数组取值节点都加入中间队列后才能被加入中间队列
	if(x->op == LARRAYOP)
	{
		for(int i = 0 ; i < length ; i++)
		{
			//对于所有中间节点
			Node *midnode = midqueue[i];
			Node *arraynode = dag[midnode->xindex];
			if(midnode->index > x->index && midnode->op == RARRAYOP && this->isIdEqual(*arraynode->mainname, *x->mainname))
			{
				//如果index比当前的index大，（表示这个节点本来就该在当前结点之后执行），且op是数组取值，且数组的名字一样
				//那么必须要在这些结点都被加入后，才能加入当前结点！
				choose = choose && flag[midnode->index];
			}
		}
	}
	if(x->op == RARRAYOP)
	{
		for(int i = 0 ; i < length ; i++)
		{
			//对于所有中间节点
			Node *midnode = midqueue[i];
			Node *arraynode = dag[x->xindex];
			if(midnode->index > x->index && midnode->op == LARRAYOP && this->isIdEqual(*arraynode->mainname, *midnode->mainname))
			{
				//如果index比当前的index大，（表示这个节点本来就该在当前结点之后执行），且op是给数组赋值
				//那么必须要在这些结点都被加入后，才能加入当前结点！
				choose = choose && flag[midnode->index];
			}
		}
	}
	return choose;
}


void Compiler::DAG()
{
	//限制一个基本块最多有100个节点
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
		//这里还得根据当前blockindex判断在哪个函数里。。
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

		//基本块的第一句话需要特殊对待，因为它的类型是不确定的可能是：①init②运算③标号④goto⑤printf⑥scanf
		//除了赋值以外的其他类型全部原样输出
		if(firstcode->op != ADDOP && firstcode->op != SUBOP && firstcode->op != MULOP && firstcode->op != DIVOP)
		{
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, false);
			begin += 1;
		}
		//如果此时基本块结束了，那么就直接continue
		if(end == begin)
			continue;
		//如果此时这个基本块就只剩下一句话没有处理了，那么直接处理这剩下的跳转语句或者是exit或者是函数开始语句，直接continue
		if(end - 1 == begin)
		{
			firstcode = this->codes[begin];
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, false);
			continue;
		}
		//此时基本块一定有至少两句四元式，那么一定至少有一句运算语句
		//这里不一定所有的基本块都是可以经过dag图优化的，所以设置一个限制，只有找到公共子表达式的才会使用dag图进行优化
		int findcount = 0;
		//首先因为最后一句话不一定能参与dag图的创建，所以，这里需要判断一下参与dag图创建的顺序
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
				//已经得到了x的信息
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
				//也已经得到了y的信息
				Node *mid = 0;
				for(int k = 0 ; k < nodeindex ; k++)
				{
					Node *node = dag[k];
					//bug:数组名如果作为结果操作数，那么如果该结点的左右操作数相等，那么也不能把这个中间节点作为新四元式的中间节点
					//因为数组名如果不一样，那么是不能作为等价的子节点存在的
					//举个例子 a[1] = b  c[1] = b 那么如果按照原来的产生方式，a和c共享一个中间节点，此时如果再来一个t = c[1] 那么它就会把a所在的结点作为左操作数，因为
					//a和c的index一样，所以这里我们对于LARRAYOP 的四元式，当且仅当 数组标识符也一样时才算作同一个中间节点
					if(!(node->isLeaf) && node->op == code->op && node->xindex == x->index && node->yindex == y->index)
					{

						if(code->op != LARRAYOP)
						{
							mid = node;
							findcount += 1;	
							//尝试：当主名字空缺时才更新它的主名字
							if(mid->flag)
							{
								*mid->mainname = *code->rstname;
							}
						}
						else{
							if(this->isIdEqual(*code->rstname, *node->mainname))
							{
								//只有当主名字一样时，才能算找到
								mid = node;
								findcount += 1;	
							}
						}
						break;
					}
				}
				if(!mid)
				{
					//如果这个中间节点未被创建
					//bug:这里一开始没有对mid赋值
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
				//然后在节点表中找z
				ListNode *z = 0;
				this->findNodeInTab(nodetab, tablength, code->rstname, &z);
				if(!z)
				{
					//没有找到
					z = new ListNode();
					z->name = code->rstname;
					//bug:这里一开始没有把z添加到nodetab中
					nodetab[tablength ++] = z;
					z->index = mid->index;
				}
				else{
					//表示在结点表中找到了z，那么如果z原来是某个结点的主名字，那么就需要设置相应结点的flag
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
		//感觉dag图优化真的有时没什么用。。
		//而且其精髓在于“公共”表达式的删除，所以我设立了findcount变量来统计遇到公共表达式的次数，如果为0次，那就别白费力气了，最后结果肯定和原来一样
		if(!findcount)
		{
			for(int j = begin ; j < end ; j++)
			{
				midcode *code = this->codes[j];
				this->pushMidCode(code->op, code->op1name, code->op2name, code->rstname, false);
			}
			continue;
		}
		std::cout << "第" << i << "块有优化" << std::endl;
		//建立好dag图和节点表以后，就可以导出新的中间代码了
		Node *queue[kMaxNodeNum] = {0};
		int queuelength = 0;
		Node *midqueue[kMaxNodeNum] = {0};
		bool flag[kMaxNodeNum] = {0};
		int midlength = 0;
		//首先把所有中间节点进入队列
		for(int j = 0 ; j < nodeindex ; j++)
		{
			Node *node = dag[j];
			if(!node->isLeaf)
			{
				midqueue[midlength ++] = node;
			}
		}
		//然后采用启发式算法进行计算
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
			//这里最好从后往前找，这样就可以保证先加入到队列中的是后出现的表达式
			for(int j = midlength - 1 ; j >= 0 ; j--)
			{
				Node *node = midqueue[j];
				if(this->canAdd(flag, node, midqueue, midlength, dag))
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
		/*最后中间节点队列的逆序就是我们想要的计算顺序，这里还需要建立优化前中间
		  代码和优化后中间代码之间的映射关系，很明显，临时变量的个数可能会减少，所以这里采取的映射方法是：如果这个临时变量在之后的基本块还活跃，那么不能删它，如果
		  不活跃，那么就可以删了
		  这里我们遍历中间节点队列里的每一个
		*/
		for(int j = queuelength - 1 ; j >= 0 ; j--)
		{
			Node *midnode = queue[j];
			std::string *mid = new std::string();
			//经过修改，是一定有主名字的,主名字是一定会被保留下来的

			*mid = *midnode->mainname;
			Node *x = dag[midnode->xindex];
			Node *y = dag[midnode->yindex];
			std::string *op1name = new std::string();
			std::string *op2name = new std::string();
			//改变为：不管是叶子节点还是中间节点，都选择它的主名字作为操作数
			*op1name = *x->mainname;
			*op2name = *y->mainname;
			

			//这时就可以生成新的中间代码
			this->pushMidCode(midnode->op, op1name, op2name, mid, false);
			//同时这时还需要把和这个节点的index相同的 标识符 #RET 临时变量 都生成相应的赋值操作，其中临时变量是需要检查它还活不活跃，即看这个基本块的out集合里有没有它
			for(int k = 0 ; k < tablength ; k++)
			{
				ListNode *listnode = nodetab[k];
				if(listnode->index == midnode->index && !this->isIdEqual(*listnode->name, *mid))
				{
					//赋值语句，就是让当前中间节点的值给 和这个节点index相同的变量
					//如果是临时变量或者局部标识符还需要判断out集合
					if(this->isOperandTemp(listnode->name))
					{
						//首先获得它在符号表中的index
						int index = -1;
						this->getIndexInTab(&index, funcref, listnode->name);
						//如果基本块出口还活跃，那么需要给它一个赋值补偿语句
						if(this->outData[blockindex][index])
						{
							this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
						}
						else{
							/*bug:
							如果不活跃了，那么需要删除这个变量，但是注意，虽然以后不活跃了，但是在这个基本块以后可能还活跃
							即下面可能会有用到这个临时变量的情况，但是如果这个四元式参与了活跃变量分析，那么它一定能得到正确的值，但是如果
							没有参与，（比如在最后一句话），那么它就需要把这个被删了的操作数换成等价的另外一个操作数
							*/
							//先获得最后一句四元式,如果最后一句四元式是下面几种，那么需要替换
							std::cout << *listnode->name << "被删去" << std::endl;
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
									//检查它的两个操作数是不是需要替换
									if(this->isIdEqual(*(code->op1name), *(listnode->name)))
									{
										//让这个节点的mainname作为新的操作数
										*code->op1name = *mid;
										std::cout << *code->op1name << " 被替换为了 " << *mid << std::endl;
									}
									if(this->isIdEqual(*code->op2name, *listnode->name))
									{
										*code->op2name = *mid;
										std::cout << *code->op2name << " 被替换为了 " << *mid << std::endl;
									}
								}
								break;
							}
						}
					}
					//不是临时变量，那么先判断是不是标识符，然后需要判断这个标识符是一个简单变量还是一个数组
					//是一个数组，一定需要生成相应的补偿语句，不是数组再判断是不是一个全局变量，如果是全局变量或者是接下来还活跃，那么就需要有补偿性的赋值语句
					//bug:如果是一个数组，那么就需要直接补上赋值语句
					else if(this->isOperandId(listnode->name))
					{

							int index = -1;
							this->getIndexInTab(&index, funcref, listnode->name);
							if(index == -1)
							{
								//是一个全局变量，那么补偿
								this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
							}
							else{
								//是一个局部变量，那么看接下来是否活跃
								if(this->outData[blockindex][index])
								{
									this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
								}
								else{
									//如果不活跃，还是需要判断最后一句四元式有没有用到这个标识符
									std::cout << *listnode->name << "被删去" << std::endl;
								}
							}					
					}
					//然后只有可能是#RET了
					else
						this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, false);
				}
			}
		}
		//这里看是否需要处理最后一句
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
		this->blockFile << "第" << i << "个基本块" << std::endl;
	}
}

//初始化
void Compiler::initOptimize()
{
	this->blockIndex = 0;
	this->optimizeMidIndex = 0;
	//初始化flag数组全为false
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

//数据流分析，以每一个函数作为一个大块分析
void Compiler:: dataFlowAnalysis()
{

	//既然是以函数作为块来分析，那么需要先按函数分
	bool **use = new bool*[this->blockIndex];
	bool **def = new bool*[this->blockIndex];
	bool **in = new bool*[this->blockIndex];
	bool **out = new bool*[this->blockIndex];
	//use def in out 都用bool数组表示
	for(int i = 0 ; i < this->funcNum ; i++)
	{
		//表示当前函数的下标
		int funcref = i;
		//接下来begin就是函数的开始，end就是函数的结束,首先遍历一遍，计算每个块的use和def集合
		int blockbegin = this->funcBlockBegin[i];
		int blockend = i + 1 >= funcNum ? this->blockIndex : this->funcBlockBegin[i + 1];
		int symnum = this->funcSymNum[funcref];
		//首先初始化所有的in / use / def /out 集合为false
		for(int j = blockend - 1 ; j >= blockbegin ; j--)
		{
			use[j] = new bool[symnum];
			def[j] = new bool[symnum];
			in[j] = new bool[symnum];
			out[j] = new bool[symnum];
		}
		for(int j = blockend - 1 ; j >= blockbegin ; j --)
		{
			//首先遍历一遍，设置好每个基本块的use集合和def集合
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
			//use / def 集合的确定
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
						//如果是这四种运算，那么根据这个更新use集合和def集合
						std::string *op1name = code->op1name;
						std::string *op2name = code->op2name;
						std::string *rstname = code->rstname;
						if(this->isOperandId(op1name) || this->isOperandTemp(op1name))
						{
							//如果操作数1是一个标识符或者是临时变量，也只有这两种变量参与分析
							//首先获得它的下标
							int index = -1;
							this->getIndexInTab(&index, funcref, op1name);
							//如果没有找到，那么说明是一个全局的变量，因为没有在局部的函数表里找到它,对于全局变量我们不考虑其数据流，所以这里需要先判断index
							//如果def集合里没有它，说明它之前并没有被def，那么就可以在use集合里加入它
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
						if(this->isOperandId(op2name) || this->isOperandTemp(op2name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op2name);
							//如果def集合里没有它，说明它之前并没有被def，那么就可以在use集合里加入它
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}

						}
						//结果操作数如果是一个简单变量标识符或者是一个临时变量
						if(this->isOperandId(rstname) || this->isOperandTemp(rstname))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, rstname);
							//如果use集合里没有它，说明它之前没有被use，那么此时在def集合里加入它
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
							//push 标识符 表示使用这个标识符
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
							//临时变量一定在函数表里，这里就不判断了
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
						//跳转语句也需要看使用情况
						std::string *op1name = code->op1name;
						std::string *op2name = code->op2name;
						if(this->isOperandId(op1name) || this->isOperandTemp(op1name))
						{
							//如果操作数1是一个标识符或者是临时变量，也只有这两种变量参与分析
							//首先获得它的下标
							int index = -1;
							this->getIndexInTab(&index, funcref, op1name);
							//如果def集合里没有它，说明它之前并没有被def，那么就可以在use集合里加入它
							if(index != -1 && !def[blockindex][index])
							{
								use[blockindex][index] = true;
							}
						}
						if(this->isOperandId(op2name) || this->isOperandTemp(op2name))
						{
							int index = -1;
							this->getIndexInTab(&index, funcref, op2name);
							//如果def集合里没有它，说明它之前并没有被def，那么就可以在use集合里加入它
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
						//scanf 一定是一个标识符，那么需要判断它是全局变量还是局部变量
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
		//进行in/out集合的计算
		bool flag = true;
		while(flag)
		{
			//flag 表示是否需要重新计算，一旦in有更新，那么flag就设置为true表示需要再算一遍
			flag = false;
			for(int j = blockend - 1 ; j >= blockbegin ; j --)
			{
				int blockindex = j;
				int symnum = this->funcSymNum[funcref];
				Block *block = this->blockArray[blockindex];
				//首先计算out[blockindex]，因为后继块最多有两个
				int next1 = block->next1;
				int next2 = block->next2;
				if(next1 != -1)
				{
					if(next2 != -1)
					{
						//那么最后结果是这两个基本块的in集合的并
						for(int k = 0 ; k < symnum ; k++)
						{
							out[blockindex][k] = in[next1][k] || in[next2][k];
						}
					}
					else{
						//最后结果是基本块1的in集合
						for(int k = 0 ; k < symnum ; k++)
						{
							out[blockindex][k] = in[next1][k];
						}
					}
				}
				else{
					if(next2 != -1)
					{
						//那么最后结果是基本块2的in集合
						for(int k = 0 ; k < symnum ; k++)
						{
							out[blockindex][k] = in[next2][k];
						}
					}
					else{
						//最后结果不变所以不处理
					}
				}
				//然后根据公式计算in集合,注意此时需要判断in集合是否被改变


				for(int k = 0 ; k < symnum ; k++)
				{
					bool result = use[blockindex][k] || (out[blockindex][k] && (! def[blockindex][k]));
					if(result != in[blockindex][k])
					{
						//如果结果不一样，那么需要设置flag为true
						flag = true;
						in[blockindex][k] = result;
					}
				}
				
			}
		}
		//到这里就把这个函数的in/out集合给求好了
		//这里输出一下结果
		for(int j = blockend - 1 ; j >= blockbegin ; j --)
		{
			int blockindex = j;
			std::cout << "第" << blockindex << "个基本块：" << std::endl;
			symbol **symtab = this->funcSymTab[funcref];
			std::cout << "use集合有：" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(use[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			std::cout << "def集合有：" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(def[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			std::cout << "out集合有：" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(out[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			std::cout << "in集合有：" << std::endl;
			for(int k = 0 ; k < symnum ; k++)
			{
				if(in[blockindex][k])
				{
					std::cout << *(symtab[k]->name) << " ";
				}
			}
			std::cout << std::endl;

			this->outData[blockindex] = new bool[symnum];
			//把out集合记录下来
			for(int k = 0 ; k < symnum ; k++)
			{
				this->outData[blockindex][k] = out[blockindex][k];
			}
		}
		std::cout << "活跃变量分析完毕" << std::endl;


		//开始构建冲突图，给每个局部的临时变量和简单变量分配属于它们的寄存器
		//目前定义：变量的活跃范围：以基本块为单位，1.该基本块的def集合有这个变量，那么这个基本块中该变量活跃2.该基本块的in集合内有这个变量，这个基本块
		//中该变量活跃
		//变量冲突：两个基本块的活跃范围有交集，那么就有冲突

		//这里需要把可以分配寄存器的给提取出来，因为冲突图只需要考虑这些变量，对于数组不需要考虑
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
		//这样就把参与冲突图建立的变量给提取出来了,这里先不管这个变量有没有跨越基本块
		//只要它是一个局部的临时变量或者是简单变量或者是参数变量，那么它就可以被分配寄存器


		ConflictNode **nodearray = new ConflictNode*[nodenum];
		for(int j = 0 ; j < nodenum ; j++)
		{
			ConflictNode *node = new ConflictNode();
			//bug:这里没有把这个新new的结点放到nodearray数组里
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
				//判断两个变量的活跃范围是否有交集
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
						//能进入这个分支，说明jflag和kflag都是true,即这两个变量之间冲突
						flag = true;
						break;
					}
				}
				if(flag)
				{
					//说明是有冲突的，那么设置相应的冲突,注意两个节点都要设置好
					node1->connect[k] = true;
					node1->edgenum ++;
					node2->connect[j] = true;
					node2->edgenum ++;
				}
			}
		}
		//冲突图构建完毕，接下来根据这个冲突图按照算法分配寄存器，这里暂定可用寄存器有14个
		int *order = new int[nodenum];
		int orderindex = 0;
		//记录哪些结点不被分配寄存器，为false表示分配寄存器，为true表示不被分配寄存器
		bool *noallocflag = new bool[nodenum];
		//记录哪些节点被移走了
		bool *outflag = new bool[nodenum];
		for(int j = 0 ; j < nodenum ; j++)
		{
			noallocflag[j] = false;
			outflag[j] = false;
		}

		while(orderindex < nodenum)
		{
			//这个标志位记录了是否找到了一个连接边数小于K的结点，如果找到了，那么直接continue，没找到，那么就选一个节点标识为不分配全局寄存器的结点
			bool continueflag = false;
			//首先遍历，找到一个连接边数小于K的结点
			for(int j = 0 ; j < nodenum ; j++)
			{
				ConflictNode *node = nodearray[j];
				if(!outflag[j] && node->edgenum < kMaxRegAvailable)
				{
					continueflag = true;
					order[orderindex ++] = j;
					//并把它从图G中移走，这里虽然移走，但是节点之前的连接状态也要记录下来，所以这里减少相应的edgenum即可
					outflag[j] = true;
					//减少和它相连的结点的edgenum
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
				//选择一个适当的结点，标识为不分配全局寄存器的结点，
				//这里选择那个连接边数最大的结点，此时所有的结点的连接边数一定都大于等于K
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
				//这样就找到了连接边数最大的结点，接下来就是把它标识为不分配全局寄存器的结点，并从图中移走
				outflag[maxedgenumindex] = true;
				noallocflag[maxedgenumindex] = true;
				order[orderindex ++] = maxedgenumindex;
				//移走就更新与它相连的edgenum
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

		//ok，经过上面的步骤，就把结点的顺序记下来了，接下来就开始按照被移走的次序，逆序分配
		//记录是否已经被加入到图中
		bool *isadd = new bool[nodenum];
		//记录寄存器的分配情况
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
			//这里按照这个节点是否被标记为不分配全局寄存器讨论
			if(noallocflag[nodeindex])
			{
				//不分配全局寄存器，那么直接把它加入图中即可
				//好像什么都不用做就可以了
			}
			else{
				//通过所有与它相连且已经被加入到这个图中的结点的分配情况来决定它的分配
				//记录了寄存器分配情况，为false表示不能被分配为这个寄存器
				bool ableflag[kMaxRegAvailable];
				for(int k = 0 ; k < kMaxRegAvailable ; k++)
				{
					ableflag[k] = true;
				}
				for(int k = 0 ; k < nodenum ; k++)
				{
					//如果相连而且相连的这个节点已经加入了新图中且相连的这个节点不是一个未分配寄存器的
					if(node->connect[k] && isadd[k] && !noallocflag[k])
					{
						//得到它的寄存器编号
						int banregindex = regalloc[k];
						//把这个寄存器ban掉
						ableflag[banregindex] = false;
					}
				}
				//上面把不能用的寄存器都ban掉了，接下来就找到第一个可以用的寄存器作为这个节点对应的寄存器
				for(int k = 0 ; k < kMaxRegAvailable ; k++)
				{
					if(ableflag[k])
					{
						//找到了第一个
						regalloc[nodeindex] = k;
						//这里把这个临时变量对应的寄存器编号给记到相应的符号表项里，便于生成目标代码时使用
						int symindex = node2sym[nodeindex];
						symbol *sym = this->funcSymTab[funcref][symindex];
						sym->regIndex = k;
						break;
					}
				}
			}
		}
		//到这里好像就分配完毕咯！

		//这里输出一下分配情况
		for(int j = 0 ; j < symnum ; j++)
		{
			symbol *sym = this->funcSymTab[funcref][j];
			std::cout << *sym->name << " 被分配了 " << sym->regIndex << " 号寄存器" << std::endl;
		}

		//释放空间
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



//窥孔优化
void Compiler::smallOptimize()
{
	//最后结果放在codes里
	int index = this->midindex;
	this->midindex = 0;
	//把所有的加0都给去掉，需要满足条件：①一个操作数是0②另一个操作数和目标操作数相同③是加法
	//或者减法时，被减数和结果一样，减数是0
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
				std::cout << "被删除" << std::endl << std::endl;
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
				std::cout << "被删除" << std::endl << std::endl;
			}
			break;
		case LABOP:
			//优化连续的label语句，把这个label后面的其他label都替换为这个label
			{
				std::string *result = code->rstname;
				//首先把这个lab语句保存下来
				this->codes[this->midindex++] = code;
				//因为会跳过一些lab语句，所以循环下一次可能不是从下一个开始，nexti记录了i应为什么值
				for(int j = i + 1 ; j < index ; j++)
				{

					midcode *labcode = this->codes[j];
					if(labcode->op != LABOP)
					{
						//如果遇到了不是lab的情况，那么直接break
						break;
					}
					else{
						//如果遇到了连续的lab，那么把所有这个lab都替换为result
						i ++;
						std::string *lab = labcode->rstname;
						for(int k = 0 ; k < index ; k++)
						{
							midcode *replacecode = this->codes[k];
							//有lab的情况就这么几种：除开labop，因为它需要被丢弃，其他的就 goto 那些branch 这两种情况
							//bug:这里一开始竟然写的是EQU NEQU LESS LESSEQU 等等 可怕
							if((replacecode->op == GOTOOP || replacecode->op == EQUOP || replacecode->op == NEQUOP || replacecode->op == LESSOP || replacecode->op == LESSEQUOP || replacecode->op == MOREOP
								|| replacecode->op == MOREEQUOP) && this->isIdEqual(*replacecode->rstname, *lab))
							{
								this->writeMidCode(replacecode);
								std::cout << "被替换为:" << std::endl;
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
			//连续两个goto，那么后一个goto可以取消的
			{
				midcode *deletecode = this->codes[i + 1];
				if(deletecode->op == GOTOOP)
				{
					//首先把当前的code保存好
					this->codes[this->midindex ++] = code;
					//后一个也是goto，那么取消这个goto,i++ 即可
					this->writeMidCode(deletecode);
					std::cout << "被删除" << std::endl << std::endl;;
					i ++;
				}
				else{
					//这里记得把code给保存了！
					this->codes[this->midindex ++] = code;
				}
			}
			break;
		default:
			this->codes[this->midindex++] = code;
		}
	}
	//这里第二遍遍历可以删除 goto label 和labbel 连续出现的情况
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
			//主要删除 goto label和后一句label是一样的情况，注意此时要保留的是后一句的lab而不是前一句的goto
			//还要注意，如果后一句不满足删除情况，那么这个goto语句是需要保留下来的
		case GOTOOP:
			{
				midcode *nextcode = this->codes[i + 1];
				if(nextcode->op == LABOP && this->isIdEqual(*nextcode->rstname, *code->rstname)){
					//此时不保存这个code即可，注意保存后一句的label
					this->writeMidCode(code);
					
					std::cout << "被删除" << std::endl << std::endl;
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