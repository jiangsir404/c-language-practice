#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<conio.h>  
#include<time.h>  
  
#define N 10000   
#define TRUE 1  
#define FALSE 0  
#define OK 1  
#define ERROR 0  
#define INFEASIBLE -1  
#define OVERFLOW -2  
typedef int Status;  
typedef char *string ;  
#define m 3 //B-树的阶  
  
/*************书的结构体***********/  
 struct Book{  
    unsigned int key;           //书的编号  
    char bname[20];             //书的名称  
    char writter[20];               //作者姓名  
    unsigned int left;              //剩余量  
    unsigned int total;             //总库存量  
}b[N];                
  
/*************B-树的存储结构***********/  
typedef Book KeyType;  
typedef struct BTNode{        
    int keynum;             //结点关键值  
    struct BTNode *parent;          //指向父结点的指针  
    KeyType key[m + 1];         //一个结点中最多存放的书的个数  
    struct BTNode *ptr[m + 1];      //指向孩子结点的指针  
}BTNode,*BTree;  
  
/*************借阅者信息（用单链表方式存储）***********/  
typedef struct Re{  
    Re *next;                   //指向下一个借阅者的指针  
    char number[20];                //借阅者编号  
    char limtdata[20];              //归还时间  
}Reader,*Read;  
Read Rroot=NULL;                      
  
/*************查找结果的存储结构体***********/  
typedef struct{  
    BTNode *pt;   
    int i;    
    int tag;   
}Result;  
BTree root = NULL;   
  
/*************函数声明***********/  
void InBookMess(KeyType &book);  
void InBookKey(KeyType &book);  
void ShowBookMess(Book book);  
void ShowBTNode(BTree p);  
void display(BTree T);  
void KeyTypeCopy(KeyType &bak,KeyType k);  
int Search(BTree p, KeyType K);  
Result SearchBTree(BTree T, KeyType K);  
void Insert(BTree &q, int i, KeyType x, BTree ap);  
void split(BTree &q, int s, BTree &ap);  
void NewRoot(BTree &T, BTree p, KeyType x, BTree ap);  
Status InsertBTree(BTree &T, KeyType K);  
Status BorrowBook(BTree T,KeyType k);  
Status ReturnBook(BTree T,KeyType k);  
void save(BTree p);  
  
/*************保存文件***********/  
void save(BTree p)  
{   
      
    FILE *fp;  
    if ((fp=fopen("book.txt","wb"))==NULL )  
    {  
        printf("创建文件失败!\n\n");  
        getchar();  
        return;  
    }  
    for(int i = 1; i <= p->keynum; i++){  
        fprintf(fp,"%d %s %s %d %d \n",p->key[i].key,p->key[i].bname,p->key[i].writter,p->key[i].left,p->key[i].total);  
        }  
        fclose(fp);  
}  
  
/*************读取文件***********/  
void read()  
{  
    FILE *fp,fp1;  
    if ((fp=fopen("book.txt","rb"))==NULL && (fp=fopen("user.txt","rb"))==NULL)  
    {  
        printf("读取文件失败!\n\n");  
        getchar();  
        return;  
    }  
  
    for(int i=1;;i++)  
    {         
        if(fscanf(fp,"%d%s%s%d%d",&b[i].key,&b[i].bname,&b[i].writter,&b[i].left,&b[i].total)==EOF)  
        {     
            break;  
        }  
        InsertBTree(root,b[i]);  
    }     
    fclose(fp);  
}  
  
  
  
/*************复制结点（将某个结点值赋给另一个结点）***********/  
void KeyTypeCopy(KeyType &bak,KeyType k){  
    bak.key = k.key;  
    strcpy(bak.bname,k.bname);  
    bak.left = k.left;  
    bak.total = k.total;  
    strcpy(bak.writter,k.writter);  
}  
  
/*************在一个结点中查找元素,返回结点的位置***********/  
int Search(BTree p, KeyType K) {      
    if(!p)  
        return -1;  
    int i=0;  
    for(i = 0; i < p->keynum && p->key[i+1].key <= K.key; i++);  
    return i;  
}  
  
/*************在m阶B树T上查找关键字K，返回结果(pt,i,tag)***********/  
Result SearchBTree(BTree T, KeyType K){   
   BTree p, q;  
   int found, i;  
   Result R;  
   p = T;   
   q = NULL;   
   found = FALSE;   
   i = 0;   
   while (p && !found) {  
      i = Search(p, K);                  
      if (i > 0 && p->key[i].key == K.key)   
          found = TRUE;      
      else {   
          q = p;    
          p = p->ptr[i];   
      }  
   }  
   if (found) {    
     R.pt = p;   
     R.i = i;    
     R.tag = 1;    
   }   
   else {        
     R.pt = q;    
     R.i = i;   
     R.tag = 0;   
   }  
   return R;                
}  
  
/*************插入一条记录***********/  
void Insert(BTree &q, int i, KeyType x, BTree ap) {  
    int n = q->keynum;     
    for (int j = n; j > i; j--) {                      
        KeyTypeCopy(q->key[j + 1],q->key[j]);   
        q->ptr[j + 1] = q->ptr[j];  
    }  
    KeyTypeCopy(q->key[i + 1],x);      
    q->ptr[i + 1] = ap;  
    if (ap)   
        ap->parent = q;    
    q->keynum++;  
}  
  
/*************分离结点***********/  
void split(BTree &q, int s, BTree &ap) {  
  int i,j,n = q->keynum;  
  ap = (BTree)malloc(sizeof(BTNode));  
  ap->ptr[0] = q->ptr[s];  
  for (i = s + 1,j = 1; i <= n; i++,j++) {  
    KeyTypeCopy(ap->key[j],q->key[i]);  
    ap->ptr[j] = q->ptr[i];  
  }  
  ap->keynum = n - s;  
  ap->parent = q->parent;  
  for (i = 0; i <= n - s; i++)       
    if (ap->ptr[i])   
        ap->ptr[i]->parent = ap;  
  q->keynum = s-1;  
}  
  
  
  
/*************生成一个树新的结点***********/  
void NewRoot(BTree &T, BTree p, KeyType x, BTree ap) {  
  T = (BTree)malloc(sizeof(BTNode));  
  T->keynum = 1;  //设置当前结点的元素个数  
  T->ptr[0] = p;  //设置左边结点的树根  
  T->ptr[1] = ap;  //设置右边的树根   
  KeyTypeCopy(T->key[1],x);  //将x 元素的结点值复制到T 的第一个元素中  
  if (p) //当孩子不空的时候就设置当前结点为孩子的双亲  
      p->parent= T;          
  if (ap)   
      ap->parent = T;    
  T->parent = NULL;  //当前结点的双亲为空  
}  
  
/*************输出书的信息***********/  
void ShowBTNode(BTree p) {  
for(int i = 1; i <= p->keynum; i++){  
    printf("\t");  
    printf("书号为:%d  ", p->key[i].key);  
    printf("书名为:%5s  ", p->key[i].bname);  
    printf("作者为:%5s  ", p->key[i].writter);  
    printf("剩余量为:%5d  ", p->key[i].left);  
    printf("总量为:%5d", p->key[i].total);  
    printf("\n");  
    }  
}  
  
/*************插入新书，在B树中插入新结点***********/  
Status InsertBTree(BTree &T, KeyType K) {  
  //在m阶B树T上结点*q的key[i]与key[i+1]之间插入关键字K。  
  BTree ap;  
  Result rs;  
  BTree q;  
  int i;  
  char addnum;  
  int finished, needNewRoot, s;  
  KeyType x;  
  if (!T){                        
    NewRoot(T, NULL, K, NULL);   
  }  
  else {  
    rs = SearchBTree(T,K);//查找元素k 在树中的位置  
    q = rs.pt;   
    i = rs.i;    
    if(rs.tag == 1){   
        if(strcmp(q->key[i].bname,K.bname) != 0){  
            printf("\n\t录入失败，原因:\n");  
            printf(".\t书号冲突，请重新为该书编号!\n\n");  
            printf("\t已经存在书号为%d 的书为:\n",q->key[i].key);  
            ShowBookMess(q->key[i]);  
            return FALSE;  
        }  
        else  
        {  
        printf("\n\t该书已经存在!\n\n");  
        printf("\t是否增加其总量(y/n):");  
        scanf("%s",&addnum);  
        if(addnum == 'Y' || addnum == 'y'){  
            q->key[i].total += K.total;   
            q->key[i].left += K.left;    
            printf("\n\t增加总量后该书的信息如下\n");  
        }     
        else{  
            printf("\n\t该书的信息如下:\n");  
        }  
        ShowBookMess(q->key[i]);  
        return FALSE;  
        }  
    }   
    x = K;    
    ap = NULL;   
    finished = needNewRoot = FALSE;       
    while (!needNewRoot && !finished) {  
      Insert(q, i, x, ap);  //插入结点  
      if (q->keynum < m)   
          finished = TRUE;  // 插入完成  
      else {  // 分裂结点*q  
        s = (m+1)/2;     
        split(q, s, ap);    
        x = q->key[s];  
        if (q->parent) {  // 在双亲结点*q中查找x的插入位置  
          q = q->parent;   
          i = Search(q, x);    
        }   
        else   
            needNewRoot = TRUE;  
      }   
    }   
    if (needNewRoot)          
      NewRoot(T, q, x, ap); // 生成新根结点*T,q和ap为子树指针  
  }  
  return OK;  
}  
  
/*************输入书的具体信息***********/  
void InBookMess(KeyType &book){   
    char s[5];  
    printf("\t请输入书号:");   
    scanf("%s",s);  
    book.key = atoi(s);   
    printf("\t请输入书名:");  
    scanf("%s",&book.bname);  
    printf("\t请输入作者:");  
    scanf("%s",&book.writter);  
    printf("\t请输入总量:");  
    scanf("%s",s);  
    book.total = atoi(s);  
    book.left = book.total;  
}  
  
/*************输入书的关键字***********/  
void InBookKey(KeyType &book){    
    char s[5];  
    printf("\t请输入书号:");   
    scanf("%s",s);  
    book.key = atoi(s);  
}  
  
/***************显示书的具体信息**********/  
void ShowBookMess(Book book){  
    printf("\t书号为:%3d\n", book.key);  
    printf("\t书名为:%3s\n", book.bname);  
    printf("\t作者为:%3s\n", book.writter);  
    printf("\t剩余量为:%3d\n", book.left);  
    printf("\t总量为:%3d\n", book.total);  
    printf("\n");  
}  
  
/*************显示整棵树的信息***********/  
void display(BTree T){  
    int i = 0;  
    if(T) {   
        ShowBTNode(T);  //显示这个结点的全部值      
        for(i=0; i<=T->keynum; i++){ //使用递归的方法显示每个结点    
            if(T->ptr[i]){  
                display(T->ptr[i]);  
            }  
        }  
    }  
}  
  
/*************借阅***********/  
Status BorrowBook(BTree T,KeyType k){  
    char s[20];  
    printf("请输入你的借阅证编号:");  
    scanf("%s",s);  
    FILE *fp=NULL;  
    fp=fopen("user.txt","w");  
    Result rs = SearchBTree(T,k);  
    if(!fp)  
    {  
        printf("无法打开文件!\n");  
    }  
    else  
    {  
        fprintf(fp,"%s\t\t",s);  
    }  
    if(rs.tag == 0){  
        printf("\t很抱歉!你要借阅的书不存在!\n");  
          
        return FALSE;  
    }  
    if(rs.pt->key[rs.i].left < 1){  
        printf("\t很抱歉!你要借阅的书已经借完!\n");  
        return FALSE;  
    }  
      
    rs.pt->key[rs.i].left--;  
    return OK;  
}  
  
/*************还书***********/  
Status ReturnBook(BTree T,KeyType k){  
    int number;  
    Result rs = SearchBTree(T,k);  
    if(rs.tag == 0){  
        printf("\t很抱歉!不存在你要还的书!\n");  
        return FALSE;  
    }  
    if(rs.pt->key[rs.i].left>=rs.pt->key[rs.i].total)  
    {  
        printf("\t该书无借出\n");  
        return FALSE;  
    }  
    else  
    {  
      rs.pt->key[rs.i].left++;  
    }  
  
}  
  
/*************显示书的信息***********/  
void ShowWriterBook(BTree p,char writer[]) {  
  for(int i = 1; i <= p->keynum; i++){  
      if(strcmp(p->key[i].writter,writer) == 0){  
          printf("\t\t\t书号为:%d   ", p->key[i].key);  
          printf("书名为:%s   ",p->key[i].bname);  
          printf("作者为:%3s\n", p->key[i].writter);  
      }  
  }  
}  
  
/*************菜单界面***********/  
char menu_selete(){  
    char ch;  
    system("cls");  
    printf("\t************************ 图书管理系统**********************\n\n");  
    printf("\t1.新书入库. \t2.查找书籍. \n");   
    printf("\t3.显示库存. \t4.借阅书籍. \n");   
    printf("\t5.归还书籍    \t6.退出系统. \n");  
    printf("\t*************************************************************\n\n");  
      
    printf("\t请选择你所需要的操作(1~6):");  
    do{       
        ch = getch();    
    }while(ch < '1' || ch > '7');  
    return ch;  
}  
  
/*************主函数***********/  
int main(){  
      
    KeyType k;  
    Result rs;    
    read();  
    while(1){  
        switch(menu_selete()){  
        case '1':  
            system("cls");  
            printf("\t------------------ 录入书信息----------------\n");  
            InBookMess(k);  
            InsertBTree(root,k);  
            printf("\t--------- 录入结束---------\n");  
            save(root);  
            printf("\t当前书库的库存信息如下：\n");  
            display(root);             
            printf("\t按任意键返回");  
            getch();  
            break;  
        case '2':  
            system("cls");  
            printf("\t------------------ 查找书信息----------------\n");  
            InBookKey(k);  
            printf("\n");  
            rs = SearchBTree(root,k);             
            if(rs.tag == 1){  
                ShowBookMess(rs.pt->key[rs.i]);  
              
            }  
            else{  
                printf("\t你要查找的书号%d 不存在!\n\n",k.key);     
              
            }  
            printf("\n\t------------------ 查找结束----------------\n");  
            printf("\t按任意键返回");  
            getch();  
            break;  
        case '3':  
            system("cls");  
            printf("\t------------------ 全部的书----------------\n\n");  
            display(root);    
            printf("\t------------------ 显示完毕-----------------\n");  
            printf("\tt按任意键返回");  
            getch();  
            break;  
        case '4':  
              
            system("cls");  
            printf("\t------------------ 借阅-----------------\n");  
            InBookKey(k);  
            if(BorrowBook(root,k)){  
                printf("\n\t借阅成功!\n");  
            }  
            else{  
                printf("\n\t借阅失败!\n");  
            }  
            printf("\n\t按任意键返回");  
            getch();              
            break;  
        case '5':  
            system("cls");  
            printf("\t----------------- 还书-----------------\n\n");  
            InBookKey(k);  
            if(ReturnBook(root,k)){  
                printf("\n\t归还成功!\n");  
            }             
            else{  
                printf("\n\t归还失败!\n");  
            }  
            printf("\n\t按任意键返回");  
            getch();  
            break;  
        case '6':  
            save(root);  
            exit(0);  
        }  
    }  
    return 0;
}  