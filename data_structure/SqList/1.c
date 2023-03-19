#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10        //初始化表长
#define INCREMENT_SIZE 5    //分配增量

typedef int Status;
typedef int Elemtype;

/*
 * 存储结构
 */
typedef struct
{
    Elemtype *elem;    //存储空间基址
    int length;        //当前长度
    int listsize;        //当前分配的表长大小
}SqList;

int getsize(int data[])
{
     printf("%p\n",data);
     return sizeof(data);


 }
 int main()
 {
     int data[]={1,2,3,4};
     int size1=getsize(data);
     int size2=sizeof(data);
     int *da=data;
     int size3=sizeof(da);
     printf("%d,%d,%d\n",size1,size2,size3);
     printf("%p,%p,%p",data,da,&data[0]);
     return 0;
}