/*
题目：八进制转换为十进制

思路： 输入八进制字符串，遍历求n = n*8 + *p -'0' 即可得到对应十进制值
*/

#include<stdio.h>
#include<math.h>

//字符串版本
void oct_to_dec(){
    char s[10],*p,n=0;
    p = s;
    gets(s);
    //遍历输入的八进制字符串
    while(*p!='\0'){
        n = n*8 + *p -'0';//减去'0'后可以将ascii字符转数字
        p++;
    }
    printf("output num:%d", n);
}

//整数版本
void oct_to_dec2(){
    int sum=0,i=0,n;
    scanf("%d", &n);
    while(n){
        sum += (n%10)*pow(8,i++);
        n = n/10;
    }
    printf("output:%d", sum);
}

int main(){
    //oct_to_dec();
    oct_to_dec2();
    return 0;
}