// 矩阵乘法运算

//思路: c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+...+a[i][k]*b[k][j]

#include<stdio.h>
#define N 3

int main(){
    //初始化a,b,c三个矩阵。
    int a[N][N] = {
        {1,2,3},
        {2,3,4},
        {3,4,5}
    };
    int b[N][N] = {
        {1,2,3},
        {2,3,4},
        {3,4,5}
    };
    int c[N][N] = {0};
    int i,j,k;
    //矩阵乘法
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    //输出二维数组
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}