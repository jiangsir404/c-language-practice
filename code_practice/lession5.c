/*
题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
(1)如果这个质数恰等于n，则说明分解质因数的过程已经结束，打印出即可。
(2)如果n<>k，但n能被k整除，则应打印出k的值，并用n除以k的商,作为新的正整数你n,
*/

#include<stdio.h>
int main(){
    int i,n,k;
    printf("input num:");
    scanf("%d", &n);
    printf("num=");
    for(i=2;i<n;i++){
        while(n!=i){
            //如果i是n的一个质因子，就反复除n=n/i,直到i不能除尽，就寻找下一个质因子。
            if(n % i == 0){
                printf("%d*",i);
                n = n / i;  
            }else{
                break;
            }
        }
        
    }
    printf("%d", n);

    return 1;
}