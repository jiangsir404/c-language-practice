/*
“同构数”是指这样的整数：它恰好出现在其平方数的右端。
如：376*376=141376。请输出10000以内的全部“同构数”。
*/

int is_tonggou_num(int n){
    int t = n*n;
    while(n){
        if(n%10 == t%10){
            n = n/10;
            t = t/10;
        }else{
            return 0;
        }
    }
    return 1;
}

#include<stdio.h>
int main(){
    int i;
    for(i=1;i<10000;i++){
        if(is_tonggou_num(i)){
            printf("num:%d\n",i);
        }
    }
}