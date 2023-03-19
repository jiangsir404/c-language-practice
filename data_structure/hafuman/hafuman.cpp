#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int weight;
	int parent;
	int lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode; //用来存储每个叶子节点的哈夫曼编码，是一个二维数组
HuffmanTree create_HuffmanTree(int *,int);  

//从所有节点中选出权值最小的根节点，并将其在数组中的序号返回
//该函数主要是供select_minium函数调用
int min(HuffmanTree ,int);

//从所有节点中选出权值最小的两个根节点，并将其序号分别保存在后两个参数中
void select_minium(HuffmanTree ,int,int &,int &);

//从叶子节点到根节点逆向求每个字符的赫夫曼编码
void HuffmanCoding(HuffmanTree ,HuffmanCode &,int);

HuffmanTree create_HuffmanTree(int *wet,int n)
{
	int total = 2*n - 1; //一颗有n个叶子节点的哈夫曼树共有2n-1个节点
	HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
	if(!HT)
	{
		printf("HuffmanTree malloc");
		exit(-1);
	}
	int i;
	for(i=0;i<n;i++) //对前n个叶子节点
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = *wet;
		wet ++;
	}

	for(;i<total;i++) //n.21-2 存放每颗二叉树的根节点
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = 0;
	}

	int min1,min2; //用来保存每一轮选出的两个weight最小且parent为0的节点，
//每一轮比较后选择出min1和min2构成一颗二叉树，最后构成一颗哈夫曼树
	for(i=n;i<total;i++)
	{
		select_minium(HT,i,min1,min2); //在0~k中选出两个最小的权值
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;

	}
	return HT;

}

void select_minium(HuffmanTree HT,int k,int &min1,int &min2)
{
	min1 = min(HT,k);
	min2 = min(HT,k);
}

int min(HuffmanTree HT,int k)
{
	int i = 0;
	int min; //用来存放weight最小且parent为0的元素的序号
	int min_weight; //用来存放weight最小且parent为0的元素的weight值
	while(HT[i].parent != 0)
		i++;
	min_weight = HT[i].weight;
	min = i;

	//选出weight最小且parent为0的元素,并将其序号赋值给min
	for(;i<k;i++)
	{
		if(HT[i].weight<min_weight && HT[i].parent==0)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}
	HT[min].parent = 1; //选出weight最小的元素后，将其parent设1,使得下次比较时排除在外
	return min;
}


void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)
{
	//用来保持指向没一个哈夫曼编码串的指针
	HC = (HuffmanCode)malloc(n*sizeof(char*)); //#HC为二重指针
	if(!HC)
	{
		printf("HuffmanCode malloc failed");
		exit(-1);
	}
	//临时空间，用来保持每次求得的哈夫曼编码串
	char *code = (char*)malloc(n*sizeof(char));
	if(!code)
	{
		printf("code malloc failed");
		exit(-1);
	}
	code[n-1] = '\0'; //编码结束符
	//求每个字符的哈夫曼编码
	int i;
	for(i=0;i<n;i++)
	{
		int current = i; //定义当前访问的节点
		int father = HT[i].parent; //当前访问的父节点
		int start = n-1;//从叶子节点便利直到根节点
		while(father != 0)
		{
			if(HT[father].lchild == current) //如果是左孩子，则编码为0
			{
				code[--start] = '0';
			}
			else{

				code[--start] = '1';
			}
			current = father; //向上访问
			father = HT[father].parent;
		}

		//为第i个字符的编码串分配存储空间
		HC[i] = (char*)malloc((n-start)*sizeof(char));
		if(!HC[i])
		{
			printf("HC[i] malloc failed!");
			exit(-1);
		}
		//将编码串从code复制到HC
		strcpy(HC[i],code+start);
	}
	free(code); //释放保持编码串的临时空间
}


void HuffmanDecode(HuffmanTree HT,int w[],char code[],int m)
{
	char *ch = code;
	int i;
	while(*ch != '\0'){
		for(i=m;HT[i].lchild!=0 && HT[i].rchild != 0;)
		{

			if(*ch == '0')
				i = HT[i].lchild;
			else if(*ch == '1')
				i = HT[i].rchild;
			++ch;
		}
		cout<<w[i-1]<<" ";
	}
}

void WPL(HuffmanTree HT,int *wet)

int main(){
	int n;
	printf("请输入需要编码的字符的个数(>1):");
	scanf("%d",&n);
	while(n<=1)
	{
		printf("字符个数必须大于１，请重新输入:");
		scanf("%d",&n);
	}
	int i;
	int *wet = (int*)malloc(n*sizeof(int));//存放每个字符的权值
	printf("请输入这%d个字符的权值:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",wet+i);
	}

	HuffmanCode HC; //保存哈夫曼编码
	HuffmanTree HT = create_HuffmanTree(wet,n);
	HuffmanCoding(HT,HC,n);
	char CodeStr[20] = {0};//存放编码后的串
	for(i=0;i<n;i++)
	{
		printf("%d:%s\n",wet[i],HC[i]);
		strcat(CodeStr,HC[i]);

	}
	printf("编码串为:%s\n",CodeStr);
	printf("对哈夫曼解码:");
	HuffmanDecode(HT,wet,CodeStr,n);
	free(wet);
	return 0;
}


