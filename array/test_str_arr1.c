//测试字符数组遍历方法

#include<stdio.h>
#include<string.h>

int main(){
    char s[] = "hello,world";
    int i;
    //遍历方式1:strlen计算字符串长度,已知长度用for循环遍历
    for(i=0;i<strlen(s);i++){
        printf("%c", s[i]);
    }
    printf("\n");

    //遍历方式2: 利用字符数组的默认结束标志'\0',用while遍历，但有些字符数组会没有，要小心。
    i = 0;
    while(s[i]!='\0'){
        printf("%c", s[i]);
        i++;
    }
    printf("\n");

    //遍历方式3:while循环指针
    char *p = s;
    while(*p!='\0'){
        printf("%c", *p);
        p++;
    }
    return 0;
}