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
		case PRINTFOP:
		case REALPARAOP:
			this->blockBegin[this->blockIndex++] = i;
			break;
		case EXITOP:
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
	this->divideToBlock();
	const int kMaxNodeNum = 100;
	for(int i = 0 ; i < this->blockIndex ; i++)
	{
		int begin = this->blockBegin[i];
		int end = i + 1 >= this->blockIndex ? this->midindex : this->blockBegin[i + 1];
		if(begin == end)
		{
			//这个基本块为空，直接跳过
			continue;
		}
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
		//如果此时基本块结束了，那么就直接continue
		if(end == begin)
			continue;
		//如果此时这个基本块就只剩下一句话没有处理了，那么直接处理这剩下的跳转语句，直接continue
		if(end - 1 == begin)
		{
			firstcode = this->codes[begin];
			this->pushMidCode(firstcode->op, firstcode->op1name, firstcode->op2name, firstcode->rstname, true);
			continue;
		}
		//此时基本块一定有至少两句四元式，那么一定至少有一句运算语句
		//这里不一定所有的基本块都是可以经过dag图优化的，所以设置一个限制，只有找到公共子表达式的才会使用dag图进行优化
		int findcount = 0;
		//接下来才是dag图的构建,注意这里最后一句肯定是不参与dag图的创建的，最后处理
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
					if(!(node->isLeaf) && node->op == code->op && node->xindex == x->index && node->yindex == y->index)
					{
						//满足条件
						mid = node;
						findcount += 1;
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
				}
				//修改为创建时就指定其主名字，这样在恢复时一定可以以创建它时的名字作为操作符
				z->index = mid->index;

				break;
			}
		}
		//感觉dag图优化真的有时没什么用。。
		//而且其精髓在于“公共”表达式的删除，所以我设立了findcount变量来统计遇到公共表达式的次数，如果为0次，那就别白费力气了，最后结果肯定和原来一样
		if(findcount)
		{
			for(int j = begin ; j < end ; j++)
			{
				midcode *code = this->codes[j];
				this->pushMidCode(code->op, code->op1name, code->op2name, code->rstname, true);
			}
			continue;
		}
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
			//经过修改，是一定有主名字的

			//如果已经有 主名字，那么这里直接用这个主名字，如果还没有主名字， 那么这里选择和这个节点相同的index 的一个名字作为主名字
			/*if(!midnode->mainname)
			{
				//没有主名字，找一个作为主名字
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
			//改变为：不管是叶子节点还是中间节点，都选择它的主名字作为操作数
			*op1name = *x->mainname;
			*op2name = *y->mainname;
			

			//这时就可以生成新的中间代码
			this->pushMidCode(midnode->op, op1name, op2name, mid, true);
			//同时这时还需要把和这个节点的index相同的 标识符 #RET 临时变量 都生成相应的赋值操作，因为无法判断之后这些变量是否还活跃
			for(int k = 0 ; k < tablength ; k++)
			{
				ListNode *listnode = nodetab[k];
				if(listnode->index == midnode->index && !this->isIdEqual(*listnode->name, *mid))
				{
					//赋值语句，就是让当前中间节点的值给 和这个节点index相同的变量
					this->pushMidCode(ADDOP, mid, new std::string("0"), listnode->name, true);
				}
			}
		}
		//这里处理最后一个跳转语句
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
		this->optimizeFile << "第" << i << "个基本块" << std::endl;
	}
}

//初始化
void Compiler::initOptimize()
{
	this->blockIndex = 0;
	this->optimizeMidIndex = 0;
}
//窥孔优化
void Compiler::smallOptimize()
{
	//最后结果放在codes里
	this->midindex = 0;
	//把所有的加0都给去掉，需要满足条件：①一个操作数是0②另一个操作数和目标操作数相同③是加法
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
				std::cout << "少了一个" << std::endl;
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
				std::cout << "少了一个" << std::endl;
				this->writeMidCode(code, true, false, false);
			}
			break;
		default:
			this->codes[this->midindex++] = code;
		}
	}
}