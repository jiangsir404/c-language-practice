#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 
#define LISTNCREMENT 10
typedef int Status;
typedef int ElemType;

typedef struct {
	ElemType *elem;
	int length;
	int size;
}SqList; 

Status InitList(SqList &L)
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);
	L.length=0;
	L.size=LIST_INIT_SIZE;	
	return OK;
}
Status DestroyList(SqList &L)
{
	free(L.elem);
	L.length=0;
	L.size=0;
}
Status ClearList(SqList &L)
{
	L.length=0;
}
Status GetElem(SqList L,int i,ElemType &e)
{
	if(i<0||i>L.length)return ERROR;
	e= L.elem[i-1];
	return OK;
}
Status GetLen(SqList L)
{
	return L.length;
}
Status Locate(SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i])return i;
	}
	if(i>=L.length) return -1;
}
Status ListInsert(SqList &L,int i,ElemType e)
{
	if(i<0||i>L.length+1)return OK;
	if(L.length>=L.size)
	{
		ElemType *newbase=(ElemType*)realloc(L.elem,LISTNCREMENT*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.size+=LISTNCREMENT;
	}
	ElemType *q=&L.elem[i-1];
	ElemType *p=&L.elem[L.length-1];
	for(;p>=q;p--)
	{
		*(p+1)=*p;
	}
	*q=e;//p跳出循环是为p=q-1; 
	L.length++; 
	return OK;
}
Status DeleteList(SqList &L,int i,ElemType &e)
{
	if(i<0||i>=L.length)return ERROR;
	e=L.elem[i-1];
	ElemType *q=&L.elem[i-1];
	ElemType *p=L.elem+L.length-1;
	for(++q;q<=p;q++)//先++q,注意循环条件为q<=p	 
	{
		*(q-1)=*q;
	}
	--L.length;
	return OK;
}

void TraveserList(SqList L)
{
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i];
	}
	cout<<endl;
}


void MergeList(SqList La,SqList Lb,SqList &Lc)
{
	ElemType *pa=La.elem,*pb=Lb.elem;//为La,Lb给一个移动标记pa,pb 
	Lc.size=Lc.length=La.length+Lb.length;
	ElemType *pc=Lc.elem=(ElemType*)malloc(Lc.size*sizeof(ElemType));//Lc malloc一块足够大的空间 
	ElemType *pa_last=La.elem+La.length-1;//找到La的尾元素 
	ElemType *pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last)//归并,注意条件不能时pa&&pb,顺序表的循环条件时pa<=pa_last 
	{
		if(*pa<=*pb)*pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last)*pc++=*pa++;  //插入La的剩余元素 
	while(pb<=pb_last)*pc++=*pb++; //插入Lb的剩余元素 
}

void menu(){
	cout<<"|------------线性顺序表-------------|"<<endl;
	cout<<" (1)插入                     (2)删除 "<<endl;
	cout<<"|(3)查找                     (4)定位|"<<endl;
	cout<<" (5)遍历                     (6)退出 "<<endl;
	cout<<"|------------线性顺序表-------------|"<<endl;
} 
int main(){
	int choice,count=0;
	SqList L;//先初始化一个顺序表结构 
	InitList(L);
	while(1){//开始进入循环操作 
		menu();
		cout<<"请输入操作数:";
		cin>>choice;
		while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6)
		{
			cin.clear();
			fflush(stdin);
			cout<<"输入无效，请重试:";
			cin>>choice;
		}
		switch(choice)
		{
			case 1:
				{
					system("cls");
					int n;
					ElemType a[81];
					cout<<"请输入插入的元素个数:";
					cin>>n;
					cout<<"请输入数据";
					for(int i=1;i<=n;i++)
					{
						cin>>a[i];
						ListInsert(L,i,a[i]);
						
					}
					break;
				}
			case 2://if else(if) if
				{
					int m;
					ElemType t;
					while(1)
					{
						cout<<"请输入需要删除的元素位置:";
						cin>>m;
						int flag=GetElem(L,m,t);
						while(flag==0)
						{
							cout<<"你输入的位置不存在，请重新输入";
							cin>>m;
							flag=GetElem(L,m,t);
						}
						GetElem(L,m,t);
						cout<<"你需要删除的数据是:"<<t<<" 是否确认删除?(y/n)";
						fflush(stdin);
						if(getchar()=='y')DeleteList(L,m,t);
						else 
						{
							cout<<"是否继续?(y/n)";
							fflush(stdin);
							if(getchar()=='n') break;
							continue;
						}
						fflush(stdin);
						cout<<"删除信息成功,是否继续?(y/n)"; 
						if(getchar()=='n') break;
					}	
					break;				
				}
			case 3:
				{
					int i;
					ElemType e;
					cout<<"请输入需要查找的元素位置:";
					cin>>i;
					while(!GetElem(L,i,e))
					{
						cout<<"该元素不存在，请重新输入:";
						cin>>i;
					}
					cout<<"你查找的元素为:"<<e<<endl;
					break;
				}
			case 4:
				{
					ElemType e;
					cout<<"请输入你需要定位的元素:";
					cin>>e;
					while(Locate(L,e)==-1)
					{
						cout<<"该元素不存在,请重新输入:";
						cin>>e;
					 } 
					 
					 cout<<"你定位的元素在第"<<Locate(L,e)+1<<"个位置"<<endl;
					break; 
				}
			case 5:
				{
					TraveserList(L);
					break;
				}
			case 6:exit(1);
		}
		
	}
	return 0;
}
