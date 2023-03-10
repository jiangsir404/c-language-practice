// 测试二位数组名与一维数组名的区别

#include<stdio.h>

int main(){
    char a[3][10] = {"BeiJing", "shangHai", "tianJin"};
    printf("%s %c\n", a+1, *(*(a+1)));
    //*(*a+1),*(*(a+1))的区别
    printf("%c %c\n", *(*a+1),*(*(a+1)));
    //**a得到首元素的值，*a 得到首行的地址。
    printf("%c\n", **a);
    //输出第二行元素的值得几种方法
    printf("%s %s %s\n", *(a+1), a+1, &a[1][0]);
    //输出第一行数据第2个元素及之后的内容
    printf("%s", *a+1);
}