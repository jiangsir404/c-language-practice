// 打印1-100以内的素数/质数
// 素数：除了1和它本身外不再有其他因数的自然数

#include<stdio.h>

//判断是否为素数的方法
int is_primer(int x){
    int i;
    for(i=2;i<x;i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    printf("1-100以内的素数有:");
    int i;
    for(i=1;i<100;i++){
        if(is_primer(i)){
            printf("%d ", i);
        }
    }
    return 0;
}