/*
题目：输入 3 个数 a,b,c，按大小顺序输出。
1.程序分析：利用指针方法。
*/

#include<stdio.h>

//利用指针做形参，可以进行深拷贝，改变原来参数的值。
int swap(int *p1,int *p2){
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

int main(){
    int a,b,c;
    printf("pls input a b c:");
    scanf("%d %d %d", &a,&b,&c);
    if(a<b) swap(&a,&b);
    if(a<c) swap(&a,&c);
    if(b<c) swap(&b,&c);
    printf("output:%d %d %d",a,b,c);
}