//*********************************************************
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//*********************************************************
typedef struct 
{
	char data[20];
	float weight;
	int lch;
	int rch;
	int fa;
}HufTree;
typedef struct node
{
	int data;
	struct node *next;
}LNode,*stack;
//*********************************************************
void HuffTree(HufTree *hf,int n);
void selecte(HufTree *hf,int *s1,int *s2,int n);
void HuffCode(HufTree *hf,int n);
void init(stack *s);
void push(stack *s,int e);
void printfstack(stack s);
//*********************************************************
int main()
{
	int n,i;
	char ch;
	HufTree *hf;
	do
	{
		printf("请输入哈夫曼编码的个数\n");
		scanf("%d",&n);
		getchar();
		hf=(HufTree *)malloc(sizeof(HufTree)*(2*n));
		for(i=1;i<=n;i++)
		{
			printf("请输入第%d个编码的信息(名称、权值)\n",i);
			scanf("%s%f",hf[i].data,&hf[i].weight);
			getchar();
		}
		HuffTree(hf,n);
		HuffCode(hf,n);
		getch();
		printf("继续输入<Y/N>\n");
		ch=getchar();
		getchar();
	}while(ch=='y'||ch=='Y');

	return 0;
}
//*********************************************************
void HuffTree(HufTree *hf,int n)
{
	int i,s1,s2;
	for(i=1;i<2*n;i++)
	{
		hf[i].fa=hf[i].lch=hf[i].rch=0;
		if(i>n)
			hf[i].weight=0;
	}
	for(i=n+1;i<2*n;i++)
	{
		selecte(hf,&s1,&s2,n);
        hf[i].lch=s1;
		hf[i].rch=s2;
		hf[i].weight=hf[s1].weight+hf[s2].weight;
		hf[s1].fa=i;
		hf[s2].fa=i;
	}
}
//*********************************************************
void selecte(HufTree *hf,int *s1,int *s2,int n)
{
	int i;
	float min=10000;
	for(i=1;i<2*n;i++)
	{
		if(min>hf[i].weight&&hf[i].fa==0&&hf[i].weight!=0)
		{
			min=hf[i].weight;
			*s1=i;
		}
	}
	for(i=1,min=10000;i<2*n;i++)
	{
		if(min>hf[i].weight&&hf[i].fa==0&&hf[i].weight!=0&&i!=*s1)
		{
			min=hf[i].weight;
			*s2=i;
		}
	}
}
//*********************************************************
void HuffCode(HufTree *hf,int n)
{
	int c,f,i;
	stack *s;
	s=(stack *)malloc(sizeof(LNode)*n);
	for(i=1;i<=n;i++)
	{
		init(&s[i]);
		c=i;
		f=hf[c].fa;
		while(f)
		{
			if(hf[f].lch==c)
				push(&s[i],0);
			else
				push(&s[i],1);
			c=f;
			f=hf[c].fa;
		}
	}
	printf("哈夫曼编码为:\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%s\t",hf[i].data);
		printfstack(s[i]);
		printf("\n");
	}
}
//*********************************************************
void init(stack *s)
{
	*s=NULL;
}
void push(stack *s,int e)
{
	stack p=(stack)malloc(sizeof(LNode));
	p->data=e;
	p->next=*s;
	*s=p;
}
//*********************************************************
void printfstack(stack s)
{
	while(s)
	{
		printf("%d",s->data);
		s=s->next;
	}
}
//*********************************************************