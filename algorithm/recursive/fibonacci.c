//计算斐波那契数列

// F(n) = 
//     1  n==0
//     1  n==1
//     F(n-1) + F(n-2)  n>1

#include<stdio.h>

int fabonacci(int n){
    if(n==0){
        return 1;
    }else if(n==1){
        return 1;
    }else{
        return fabonacci(n-1) + fabonacci(n-2);
    }                         
}

void main(){
    int n = 10,i; //输出前10个斐波那契数列
    for(i=0;i<n;i++){
        printf("%d ", fabonacci(i));
    }
    
}