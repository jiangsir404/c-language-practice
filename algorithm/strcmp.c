//自定义实现strcmp函数的功能

#include<stdio.h>
#include<string.h>

int main(){
    char s1[100],s2[100];
    int i=0,resu;
    printf("input s1:");
    gets(s1);
    printf("input s2:");
    gets(s2);
    //遍历相同字符的前缀
    while((s1[i]==s2[i]) && (s1[i]!='\0')) i++;
    //如果s1和s2同时结束，则相等
    if(s1[i] == '\0' && s2[i] == '\0'){
        resu = 0;
    }else{
        resu = s1[i] - s2[i];
    }
    printf("result:%d\n", resu);
}