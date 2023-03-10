/*
题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时
　　　共有5个数相加)，几个数相加有键盘控制。

思路: 2=0+2,22=20+2,222=220+2,2222=2220+2
即每项的数都是前一项*10+2,得到tmp=tmp*10+a,再把每个tmp相加即可。
*/

#include<stdio.h>
#include<math.h>

int main(){
    int a,n,sum=0,i,tmp;
    printf("please input a n:");
    scanf("%d %d", &a,&n);
    tmp = 0;
    for(i=1;i<=n;i++){
        // 2=0+2,22=20+2,222=220+2,2222=2220+2
        tmp = tmp * 10 + a;
        sum += tmp;
        printf("%d, %d\n", tmp,sum);
    }
    return 0;
}