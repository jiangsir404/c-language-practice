/*
题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
*/

#include<stdio.h>
int main(){
    int a,b,c,d,e,n;
    scanf("%d", &n);
    a = n/10000; //分解出万位
    b = n%10000/1000; //分解出千位
    c = n%1000/100; //分解出百位
    d = n%100/10; //分解除十位
    e = n%10; //分解出个位

    if(a!=0){
        printf("n=5,%d%d%d%d%d", e,d,c,b,a);
    }else if(b!=0){
        printf("n=4,%d%d%d%d", e,d,c,b);
    }else if(c!=0){
        printf("n=3,%d%d%d", e,d,c);
    }else if(b!=0){
        printf("n=2,%d%d", e,d);
    }else{
        printf("n=1,%d", e);
    }
    
}