// 自定义实现字符串strcpy函数的功能

#include<stdio.h>
#include<string.h>

int main(){
    //将s2中的字符串内容拷贝到s1中去，并加上\0
    char s1[80],s2[80];
    int i;
    printf("input s2:");
    scanf("%s", s2);
    for(i=0;i<strlen(s2);i++){
        s1[i] = s2[i];
    }
    s1[i] = '\0';//strcpy复制时最后的\0要加上去
    puts(s1);
}