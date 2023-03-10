/*
题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
*/

#include<stdio.h>

 void print_reverse_str(char *str){
     if(*str == '\0'){
         return ;
     }else{
         print_reverse_str(str++);
         printf("%c",*str);
     }
 }

int main(){
    char s[10];
    printf("pls input str:");
    scanf("%s", s);
    print_reverse_str(s);
    return 0;
}