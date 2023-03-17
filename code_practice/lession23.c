/*
题目：八进制转换为十进制

思路： 输入八进制字符串，遍历求n = n*8 + *p -'0' 即可得到对应十进制值
*/

#include<stdio.h>
int main(){
    char s[10],*p,n=0;
    p = s;
    gets(s);
    //遍历输入的八进制字符串
    while(*p!='\0'){
        n = n*8 + *p -'0';//减去'0'后可以将ascii字符转数字
        p++;
    }
    printf("output num:%d", n);
    return 0;
}