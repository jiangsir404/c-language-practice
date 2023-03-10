/*
题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
*/

#include<stdio.h>

 int print_reverse_str(char *str){
     if(*(str+1) == '\0'){
         return 0;
     }else{
         print_reverse_str(++str);
         printf("%c",*str);
     }
 }

int main(){
    char s[20];
    printf("pls input str:");
    scanf("%s", s);
    //printf("%s", s);
    print_reverse_str(s);
    printf("%c", s[0]);
    return 0;
}