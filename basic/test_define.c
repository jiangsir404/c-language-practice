//测试define 符号常量的易错点，
    // - 带括号与不带括号的区别
    // - f(6) 与 f(3+3) 的区别

#include<stdio.h>

#define f(x) x*x
#define g(x) (x*x)

int main(){
    int x = 2;
    printf("%d, %d\n", f(6), f(3+3));
    printf("%d, %d\n", f(4)/f(2), g(4)/g(2));
}