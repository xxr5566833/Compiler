#include "stdafx.h"
#include "Compiler.h"
////////////////////////////////////////////////
//主函数									  //
//											  //
////////////////////////////////////////////////



/*int main(int argc, char *argv[])
{

	char path[50];
	std::cout << "请输入文件路径 :" << std::endl;
	std::cin >> path;
	Compiler *c = new Compiler(path);
	c->begin();

}*/

bool binary(int a[], int size, int target)
{
	int i = size - 1;
	int j = 0;
	while(j <= i)
	{
		int mid = (i + j) / 2;
		if(a[mid] == target)
		{
			return true;
		}
		else if(a[mid] < target)
		{
			j = mid + 1;
		}
		else
		{
			i = mid - 1;	
		}
	}
	return false;
}

void insertSort(int a[], int size)
{
	int b[50] = {0};
	int bsize = 0 ;
	for(int i = 0 ; i < size ; i++)
	{
		int key = a[i];
		bool flag = false;
		for(int j = 0 ; j < bsize ; j++)
		{
			int bkey = b[j];
			if(key < bkey)
			{
				for(int k = bsize ; k > j ; k--)
				{
					b[k] = b[k - 1];
				}
				b[j] = key;
				bsize ++;
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			b[bsize++] = key;
		}
	}
	std::cout << "排序后" << std::endl;
	for(int i = 0 ; i < bsize ; i++)
	{
		std::cout << b[i] << " ";
	}
}

void insertSort2(int a[], int size)
{
	for(int i = 1 ; i < size ; i++)
	{
		int key = a[i];
		int k = i - 1;
		while(k >= 0 && a[k] < key)
		{
			a[k + 1] = a[k];
			k --;
		}
		a[k + 1] = key;
	}
	for(int i = 0 ; i < size ; i++)
	{
		std::cout << a[i] << " ";
	}
}

void merge(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	while(i < j && j <= right)
	{
		int key1 = a[i];
		int key2 = a[j];
		if(key1 > key2){
			for(int k = j ; k > i ; k --)
				a[k] = a[k -1];
			a[i] = key2;
			j++;
		}
		i++;
	}
	
}

void mergeSort(int a[], int left, int right)
{
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, right);
	}
}

void insertSortRecursion(int a[], int size, int right)
{
	
	if(right <= size - 1 && right > 0)
	{
		insertSortRecursion(a, size, right - 1);
		int i = right - 1;
		int key = a[right];
		while(i >=0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i --;
		}
		a[i + 1] = key;
	}
}


int findMaxSubarray(int a[], int left, int right, int *maxleftindex, int *maxrightindex)
{
	if(left == right)
	{
		*maxleftindex = *maxrightindex = left;
		return a[left];
	}
	else{
		int mid = (left + right) / 2;
		int lefti, leftj;
		int leftval = findMaxSubarray(a, left, mid, &lefti, &leftj);
		int righti, rightj;
		int rightval = findMaxSubarray(a, mid + 1, right, &righti, &rightj);
		int leftindex = mid;
		int leftsum = 0;
		int leftmax = -10000000;
		int rightindex = mid + 1;
		int rightsum = 0;
		int rightmax = -10000000;
		for(int i = mid ; i >= left ; i --)
		{
			leftsum += a[i];
			if(leftsum > leftmax)
			{
				leftmax = leftsum;
				leftindex = i;
			}
		}
		for(int j = mid + 1; j <= right ; j++)
		{
			rightsum += a[j];
			if(rightsum > rightmax)
			{
				rightmax = rightsum;
				rightindex = j;
			}
		}
		int crosssum = rightmax + leftmax;
		if(crosssum > leftval)
		{
			if(crosssum > rightval)
			{
				*maxleftindex = leftindex;
				*maxrightindex = rightindex;
				return crosssum;
			}
			else{
				*maxleftindex = righti;
				*maxrightindex = rightj;
				return rightval;
			}
		}
		else{
			if(rightval > leftval)
			{
				*maxleftindex = righti;
				*maxrightindex = rightj;
				return rightval;
			}
			else{
				*maxleftindex = lefti;
				*maxrightindex = leftj;
				return leftval;
			}
		}
	}
}

int findMaxSubarray2(int a[], int size, int *maxindexi, int *maxindexj)
{
	int max = 0x80000001;
	int sum = 0;
	for(int i = 0 ; i < size ; i++)
	{
		int sumj = 0;
		int indexj = -1;
		int maxj = 0x80000001;
		for(int j = i ; j >= 0 ; j--)
		{
			sumj += a[j];
			if(sumj > maxj)
			{
				maxj = sumj;
				indexj = j;
			}
		}
		if(maxj > max)
		{
			*maxindexi = indexj;
			*maxindexj = i;
			max = maxj;
		}
	}
	return max;
}

inline int parent(int i)
{
	return (i + 1) >> 1 < 1 ? 0 : ((i + 1) >> 1) - 1;
}

inline int left(int i)
{
	return ((i + 1) << 1) - 1;
}

inline int right(int i)
{
	return (i + 1) << 1;
}

void maxHeapify(int a[], int heapsize, int index)
{
	while(1)
	{
		int largest = index;
		int l = left(index);
		int r = right(index);
		if(l < heapsize && a[l] > a[index])
		{
			largest = l;
		}
		if(r < heapsize && a[r] > a[largest])
		{
			largest = r;
		}
		if(largest != index)
		{
			a[largest] = a[largest] ^ a[index];
			a[index] = a[largest] ^ a[index];
			a[largest] = a[largest] ^ a[index];
			index = largest;
		}
		else{
			break;
		}
	}
}

void buildMaxHeap(int a[], int size)
{
	for(int i = ((size >> 1)- 1) ; i >= 0 ; i -- )
	{
		maxHeapify(a, size, i);
	}
}
//exchange就不需要另外一个数组了
void heapsort(int a[], int size)
{
	buildMaxHeap(a, size);
	for(int i = size - 1; i >= 1 ; i--)
	{
		a[0] = a[0] ^ a[i];
		a[i] = a[0] ^ a[i];
		a[0] = a[0] ^ a[i];
		maxHeapify(a, i, 0);
	}
}

int maximum(int a[])
{
	return a[0];
}

int heapExtractMax(int a[], int size)
{
	if(size < 1)
	{
		std::cout << "heap size err" << std::endl;
		return -1;
	}
	int max = a[0];
	a[0] = a[size - 1];
	size -= 1;
	maxHeapify(a, size, 0);
	return max;

}

void heapIncreaseKey(int a[], int size, int index, int key)
{
	if(index >= size || key < a[index])
	{
		std::cout << "err" <<std::endl;
	}
	a[index] = key;
	while(index != 0 && a[parent(index)] < a[index])
	{
		int par = parent(index);
		a[par] = a[par] ^ a[index];
		a[index] = a[par] ^ a[index];
		a[par] = a[par] ^ a[index];
		index = par;
	}
}

void maxHeapInsert(int a[], int size, int key)
{
	a[size + 1] = 0x80000001;
	heapIncreaseKey(a, size + 1, size, key);
}

//使用异或进行交换时，如果两个被交换的是同一个变量（在交换数组元素时尤为注意），那么这个变量会变成0
void quickSort(int a[], int left, int right)
{
	if(left < right)
	{
		int key = a[right];
		int i = left - 1;
		for(int j = left ; j < right ; j++)
		{
			if(a[j] < key)
			{
				i = i + 1;
				int temp ;
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
		a[right] = a[i + 1];
		a[i + 1] = key;
		quickSort(a, left, i);
		quickSort(a, i + 2, right);
	}
}

void countSort(int a[], int size)
{
	int b[50] = {0};
	int c[50] = {0};
	for(int i = 0 ; i < size ; i++)
	{
		c[a[i]] = c[a[i]] + 1;
	}
	for(int i = 0 ; i < size - 1 ; i++)
	{
		c[i + 1] += c[i];
	} 
	for(int i = size - 1 ; i >= 0 ; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]] -= 1;
	}
	for(int i = 0 ; i < size ; i++)
	{
		std::cout << b[i] << " ";
	}
}

int queue[50] = {0};
int length = 10;
int head = 0;
int tail = 0;

//队列只能满足n-1个元素
int enqueue(int key)
{
	if(head == (tail + 1) % length)
	{
		std::cout << "队列为满" << std::endl;
		return -1;
	}
	queue[tail] = key;
	tail = (tail + 1) % length;
	for(int i = head ; i < tail ; i = (i + 1) % length)
	{
		std::cout << queue[i] << " ";
	}
	std::cout << std::endl;
}

int dequeue()
{
	if(head == tail)
	{
		std::cout << "队列为空" << std::endl;
		return 0x8000001;
	}
	int key = queue[head];
	head = head + 1;
	if(head == length)
	{
		head = 0;
	}
	for(int i = head ; i < tail ; i = (i + 1) % length)
	{
		std::cout << queue[i] << " ";
	}
	std::cout << std::endl;
	return key;
	

}

typedef struct Node2{
	int key;
	struct Node2 *next;
	struct Node2 *prev;
}node2;

node2 *NIL;


void insert(int key)
{
	node2 *n = new node2();
	n->key = key;
	
	NIL->next->prev = n;
	n->prev = NIL;
	n->next = NIL->next;
	NIL->next = n;
}

void init()
{
	NIL = new node2();
	NIL->next = NIL;
	NIL->prev = NIL;
}

bool isEmpty()
{
	return NIL->next == 0;
}
//search时不需要检查是否是NIL，只需要把NIL的key域设置为要search的key，然后只需要检查key是否和要search的key相同即可
//循环时，会从NIL的下一个开始，所以只有再重新开始循环时才会遇到NIL
node2 *search(int key)
{
	for(node2 *n = NIL->next ; n != NIL ; n = n -> next)
	{
		if(n->key == key)
		{
			return n;
		}
	}
	return 0;
}

node2 *del(node2 *n)
{
	n->next->prev = n ->prev;
	n->prev->next = n->next;
	return n;
	
}

void converse()
{
	node2 *end = NIL->prev;
	node2 *n = NIL->next;
	NIL->next = end;
	while(n != end)
	{
		node2 *next = n->next;
		n->next = end->next;
		end->next->prev = n;
		end->next = n;
		n->prev = end;
		n = next;

	}

}
typedef struct singleNode{
	int key;
	struct singleNode *next;
}sNode;

sNode *HEAD = 0;

typedef struct BTREE{
	struct BTREE *p;
	struct BTREE *left;
	struct BTREE *right;
	int key;
}bTree;

bTree *root;

void traversal(bTree *root)
{
	if(root)
	{
		std::cout << root->key << " ";
		traversal(root->left);
		traversal(root->right);
	}
}

void traversal2()
{
	bTree *list[50] = {0};
	int top = 0;
	list[top++] = root;
	while(top != 0)
	{
		bTree *temproot = list[--top];
		std::cout << temproot->key << " ";
		if(temproot->left)	list[top++] = temproot->left;
		if(temproot->right) list[top++] = temproot->right;
	}
}

int main(int argc, char *argv[])
{
	int a[10] = {1, 2, 3, 4, 5, 6};
	root = new bTree();
	root->key = 84;
	root->left = new bTree();
	root->left->key = 20;
	root->left->left = new bTree();
	root->left->left->left = 0;
	root->left->left->right = 0;
	root->left->left->key = 12;
	root->left->right = new bTree();
	root->left->right->left = 0;
	root->left->right->right = 0;
	root->left->right->key = 8;

	root->right = new bTree();
	root->right->key = 64;
	root->right->left = 0;
	root->right->right = 0;

	traversal2();
}