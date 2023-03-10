// 测试printf的输出

// - 进制输出
// - 格式输出

#include<stdio.h>
int main(){
    //进制输出
    int a = 252;
    printf("a=%o a=%#o\n", a, a);
    printf("a=%x a=%#x\n", a, a);
    
    //格式化输出
    float PI = 3.141592654;
    printf("%5d\n", 123); //长度为5，不够填充空格
    printf("%f\n", PI);//%f类型默认只能带六位小数
    printf("%5.3f\n", PI); //长度为5， 带三位小数
    printf("%10f\n", PI); //总长度为10, 但f之能带6为小数，还有两个空格填充
    return 0;
}