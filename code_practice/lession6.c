/*
题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
1.程序分析：利用while语句,条件为输入的字符不为'\n'.
*/

#include<stdio.h>
int main(){
    char s[80], *str;
    gets(s);//gets不能直接赋值给一个字符指针，需要malloc才行。
    str = s;
    int abc_count=0,space_count=0,other_count=0;
    while(*str != '\0'){
        if('A'<=*str&&*str<='Z' || 'a'<=*str&&*str<='z'){
            abc_count ++;
        }
        else if(*str == ' '){
            space_count ++;
        }else{
            other_count ++;
        }
        str ++;
    }
    printf("total count:%d %d %d", abc_count,space_count,other_count);
    return 0;
}