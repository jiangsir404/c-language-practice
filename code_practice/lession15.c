/*
题目：将一个数组逆序并输出。
*/


#include<stdio.h>
#define N 5
int main(){
    int a[N]={1,2,3,4,5};
    int i,t;
    //交换数组首尾元素
    for(i=0;i<N/2;i++){
        t = a[i];
        a[i] = a[N-i-1];
        a[N-i-1] = t;
    }
    //输出数组
    for(i=0;i<N;i++){
        printf("%d ", a[i]);
    }
}