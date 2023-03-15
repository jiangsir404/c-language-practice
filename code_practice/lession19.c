/*
题目：编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，调用函数
　　　1/1+1/3+...+1/n(利用指针函数)

思路:
多项式求和算法, 重点是找到每一项的表达式。
    if(n % 2 == 0){
        //偶数
        t = 2*i;
        sum += 1/t;
    }else{
        //奇数
        t = 2*(i-1)+1;
        sum += 1/t;
    }
*/

#include<stdio.h>

int main(){
    int n,i;
    float t, sum=0;
    printf("pls input n:");
    scanf("%d", &n);
    for(i=1;t<n;i++){
        if(n % 2 == 0){
            //偶数
            t = 2*i;
            sum += 1/t;
        }else{
            //奇数
            t = 2*(i-1)+1;
            sum += 1/t;
        }
        printf("%f ", t);
    }
    printf("sum=%f", sum);
    return 0;
}