/*
题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
1.程序分析：在10万以内判断，先将该数加上100后再开方，再将该数加上268后再开方，如果开方后
　　　　　　的结果满足如下条件，即是结果。请看具体分析：
*/

#include<stdio.h>
#include<math.h>

int main(){
    long int i;
    long int x,y;
    // printf("%lf", sqrt(100));
    for(i=1;i<10000;i++){
        x = sqrt(i+100);
        y = sqrt(i+268);
        //或者x*x-100 == i && i ==y*y-268 
        if(x*x==i+100&&y*y==i+268){
            printf("find num:%d,%d %d\n", i,x,y);
        }
    }
}