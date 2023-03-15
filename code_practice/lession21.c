/*
题目：字符串排序,从小到大。
*/

#include<stdio.h>
#include<string.h>

void swap(char *p1,char *p2){
    char s[50];
    strcpy(s,p1);
    strcpy(p1,p2);
    strcpy(p2,s);
}

int main(){
    char s1[50],s2[50],s3[50];
    printf("pls input s1 s2 s3:");
    scanf("%s %s %s", s1,s2,s3);
    if(strcmp(s1,s2)>0) swap(s1,s2);
    if(strcmp(s1,s3)>0) swap(s1,s3);
    if(strcmp(s2,s3)>0) swap(s2,s3);
    printf("%s %s %s", s1,s2,s3);
    return 0;
}