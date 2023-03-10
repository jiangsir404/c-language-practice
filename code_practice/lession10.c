/*
题目：利用递归方法求5!。
1.程序分析：递归公式：fn=fn_1*4!
*/

#include<stdio.h>

int func(n){
    if(n==1){
        return 1;
    }else{
        return n*func(n-1);
    }
}

int main(){
    printf("%d", func(5));
}