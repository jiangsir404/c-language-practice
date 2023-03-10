/*
题目：求1+2!+3!+...+20!的和
1.程序分析：此程序只是把累加变成了累乘。
*/

#include<stdio.h>
int main(){
    int i;
    long int t=1,s;
    for(i=1;i<=20;i++){
        t *= i;
        s += t;
        printf("%d %d\n", i,t);
    }
    printf("total top 20:%ld", s);
    return 0;
}