/*
题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。　　　

思路:分解出该整数的每一位
*/

#include<stdio.h>
int main(){
    int a,b,c,d,e,n;
    printf("pls input num:");
    scanf("%d", &n);
    a = n/10000; //分解出万位
    b = n%10000/1000; //分解出千位
    c = n%1000/100; //分解出百位
    d = n%100/10; //分解除十位
    e = n%10; //分解出个位

    if(a==e && b==d){
        printf("the num is yes");
    }else{
        printf("no");
    }
    return 0;
}