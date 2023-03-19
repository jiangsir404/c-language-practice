// linklist.c 

#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;


typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

// ---------------基础操作函数----------------------- 
void InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	if (!L){
		printf("init fail!\n");
		exit(0);
	}
	L->next = NULL;
}

LNode *GetElem(LinkList &L, int i){
	LNode *p=L;
	int j=0;
	while(j<i){
		p = p->next;
		j++;
	}
	return p;
}

void InsertElem(LinkList &L, int i, ElemType e){
	LinkList p = GetElem(L, i-1); // 按位置查找元素 
	LinkList s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("insert %d success\n", e);
}

void PrintList(LinkList &L){
	LNode *p=L->next;
	printf("PrintList: ");
	while(p != NULL){
		printf("%d, ", p->data);
		p = p->next;
	}
}

// ---------------高级操作函数----------------------- 

// 头插法逆置链表 
void Reverse1(LinkList &L){
	LinkList p=L->next,r; //设置遍历指针和后继指针 
	L->next = NULL; //摘下头节点
	while(p!=NULL){
		//头插法依次插入各个节点 
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
		
	} 
	PrintList(L);
}

// 指针反转方法逆置链表
void Reverse2(LinkList &L){
	LinkList h=L,p=L->next,r=p->next; //设置前继指针，遍历指针，后继指针 
	p->next = NULL;
	while(r){
		//h,p,r同步后移
		h = p;
		p = r;
		r = p->next;
		p->next = h; //逆置指针 
	} 
	L->next = p;
	PrintList(L);
} 

//删除最小元素函数 
LinkList Delete_Min_Elem(LinkList &L){
	;
}

//链表归并

//链表字串匹配 

int main(){
	LinkList L;
	InitList(L);
	for(int i=1;i<10;i++){
		InsertElem(L, i, i);
	}
	PrintList(L);
	// 测试高级操作函数 
	Reverse1(L);
	Reverse2(L);
}
