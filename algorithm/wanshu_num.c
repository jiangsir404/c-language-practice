// 找出 1000 以内的所有完数。
// 一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如 6=1＋2＋3

#include<stdio.h>

void main(){
    int n,sum,i;
    for(n=2;n<1000;n++){
        sum = 0;
        //将所有的因数相加,注意1也是
        for(i=1;i<n;i++){
            if(n%i==0) sum += i;
        }
        if(sum==n){
            printf("%d, its factors are:", n);
            for(i=1;i<n;i++){
                if(n%i==0) printf("%d ",i);
            }
        printf("\n");
        }
    }
}