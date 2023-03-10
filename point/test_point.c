// 测试指针遍历一维数组和二维数组
//遍历数组的结束标志是地址大小比较，遍历字符数组的结束标志是*p!='\0'

#include<stdio.h>
int main(){
    //遍历一维数组
    int b[5] = {1};
    int *ps;
    for(ps=b;ps<b+5;ps++){
        printf("%d", *ps);
    }
    printf("\n");

    //遍历二维数组
    int a[5][5] = {{1}, {2,3}, {3,4}, {4}, {5}};
    int *p;
    for(p=a[0];p<a[0]+25;p++){
        printf("%d ", *p);
    }
    printf("\n");

    //遍历字符数组
    char s[] = "hello,world";
    char *p1;
    for(p1=s;*p1!='\0';p1++){
        printf("%c", *p1);
    }
}