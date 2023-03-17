/*
题目：从键盘输入一个字符串，将小写字母全部转换成大写字母，然后输出到一个磁盘文件“test”中保存。
输入的字符串以！结束。
*/

#include<stdio.h>

int main(){
    char s[100];
    printf("pls input str:");
    gets(s);
    int i=0;
    while(s[i]!='!'){
        if(s[i]>='a'&&s[i]<='z'){
            s[i] -= 32;
        }
        i++;
    }
    //puts(s);
    FILE *fp;
    fp = fopen("test.txt", "w");
    fputs(s,fp);
    fclose(fp);
    //读取文件内容并打印
    fp = fopen("test.txt", "r");
    fgets(s, strlen(s)+1,fp);
    printf("%s", s);
    return 0;
}