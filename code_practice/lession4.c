/*
题目：判断101-200之间有多少个素数，并输出所有素数。
1.程序分析：判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除，
　　　　　　则表明此数不是素数，反之是素数。
*/

#include<stdio.h>
#include<math.h>

int is_primer(num){
    int i;
    for(i=2;i<=sqrt(num);i++){
        if(num % i == 0) return 0; 
    }
    return 1;
}

int main(){
    int i;
    for(i=1;i<200;i++){
        if(is_primer(i)){
            printf("%d ", i);
        }
    }
}