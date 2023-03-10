//测试stdlib.h库文件

#include<stdio.h>
#include<stdlib.h>


int main(){
    char a[] = "100";
    char b[] = "200";
    int c,d;
    //atoi:ascii to int 即字符串转换成整形。还有atol,atof转换成长整数和实数。
    printf("%d", atoi(a)+atoi(b));

    return 0;
}