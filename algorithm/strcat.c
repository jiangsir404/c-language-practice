// 自定义实现字符串strcpy函数的功能

//思路: 快慢指针方法

#include<stdio.h>
#include<string.h>

int main(){
    char s1[80],s2[80];
    int i=0,j=0;
    printf("input s1:");
    scanf("%s", s1);
    printf("input s2:");
    scanf("%s", s2);

    //快慢指针i和j
    while(s1[i]!='\0'){
        i++;
    }
    while(s2[j]!='\0'){
        s1[i++] = s2[j++];
    }
    s1[i] = '\0';
    puts(s1);
}