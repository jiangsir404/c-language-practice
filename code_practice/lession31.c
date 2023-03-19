/*
编写一个函数，其功能是计算二维数组每行之和以及每列之和。
*/

#include<stdio.h>
#define M 3
#define N 3

int main(){
    int a[M][N]= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int row=0,col=0,i,j;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            col += a[i][j];
            row += a[j][i];
        }
        printf("every col sum:%d row sum:%d\n", col,row);
        col = 0;
        row = 0;
    }
    return 0;
}