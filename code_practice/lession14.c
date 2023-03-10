/*
题目：求一个3*3矩阵对角线元素之和
1 2 3
4 5 6
7 8 9
思路：利用双重for循环控制输入二维数组，再将a[i][i]累加后输出。
*/

#include<stdio.h>

int main(){
    int a[3][3]={0};
    int i,j,sum;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d", &a[i][j]);
            //主对角线和副对角线的值
            if(i==j || i+j==2){
                sum += a[i][j];
            }
        }
    }
    printf("sum: %d", sum);
    return 0;
}