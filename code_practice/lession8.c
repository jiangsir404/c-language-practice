/*
题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
1.程序分析：请抓住分子与分母的变化规律。
*/


#include<stdio.h>
int main(){
    float a,b,c,tmp,sum;
    int i;
    b=2.0;
    a=1.0;
    //printf("%f/%f", b,a);
    for(i=0;i<20;i++){
        tmp = b/a;
        printf("%f/%f %f\n", b, a, tmp);
        sum += tmp;
        c = b;
        b = a + b;
        a = c;
    }
    printf("total top 20 sum:%f", sum);
    
    return 0;
}