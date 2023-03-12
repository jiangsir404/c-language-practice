/*
题目：求一个3*3矩阵主副对角线元素之和
1 2 3
4 5 6
7 8 9
思路：利用双重for循环控制输入二维数组，主对角线元素为i=j,副对角线元素为i+j=N-1
*/

#include<stdio.h>
#define N 3

int main(){
    int a[N][N]={0};
    int i,j,sum;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d", &a[i][j]);
            //主对角线和副对角线的值
            if(i==j || i+j==N-1){
                sum += a[i][j];
            }
        }
    }
    printf("sum: %d", sum);
    return 0;
}