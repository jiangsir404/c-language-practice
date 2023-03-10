//测试math库

#include<stdio.h>
#include<math.h>

int main(){
    int i;
    //开方运算
    i = sqrt(100);
    printf("%d, %d\n", i,(int)sqrt(100));

    //次方运算
    i = pow(10,3);
    printf("pow(10,3)=%d\n", i);

    //取绝对值
    i = abs(-20);
    printf("abs(-20)=%d\n", i);

    //求三角函数值
    printf("%lf,%lf\n", acos(1),asin(1));

    //求指数和对数的值
    double j;//必须是double 值
    j = exp(5.0);
    printf("%f ", log10(100));
    printf("%f,%f", j, log(j));
}