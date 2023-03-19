/*
题目：有两个磁盘文件 A 和 B,各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），
输出到一个新文件 C 中。
*/

#include<stdio.h>

int main(){
    FILE *fp1, *fp2;
    char s1[50],s2[50];
    fp1 = fopen("test.txt", "r");
    fp2 = fopen("test1.txt", "r");
    fgets(s1,sizeof(char)*50, fp1);
    fgets(s2,sizeof(char)*50, fp2);
    puts(s1);
    puts(s2);
}