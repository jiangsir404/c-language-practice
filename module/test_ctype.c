//测试ctype.h

#include<stdio.h>
#include<ctype.h>

int main(){
    int a = 67;
    int b = 49;
    //isalnum 判断该ascii是否为字母或数字,isalpha是否为字母
    printf("%d %d\n", isalnum(a),isalpha(a));
    printf("%d %d\n", isdigit(a),isdigit(b));
    printf("%d %d\n", islower(a),isupper(a));
    return 0;
}