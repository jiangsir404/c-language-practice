// 求m和n的最大公约数和最大公倍数
// 方法：辗转相除法
// eg: 12 15的最大公约数为3，最小公倍数为60
// 最小公倍数=m*n/最大公约数

#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int a, b, m,n,temp;
    printf("input m,n:");
    scanf("%d %d", &m,&n);
    a = m, b = n;
    //确保m>n
    if(m<n){
        swap(&m,&n);
    }
    // printf("%d %d\n", m,n);
    while(n!=0){
        temp = m % n;
        m = n;
        n = temp;
    }
    printf("m:%d,n:%d,temp:%d", m,n,temp);
    printf("the max common divisor is:%d\n", m);
    printf("the min common data: 最小公倍数为:%d", a*b/m);
}