//矩阵转置算法

#include<stdio.h>
#define N 3

//转置交换矩阵
void swap(int *p){
    int i,j,t;
    //注意j是从i开始，否则第二行会再次交换回来。
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            t = *(p+3*i+j);
            *(p+3*i+j) = *(p+3*j+i);//a[1] <-> a[3]
            *(p+3*j+i) = t;
            //printf("%d<->%d ", *(p+3*i+j),*(p+3*j+i));
        }
    }
}

//用指针输出二维数组矩阵
void print(int *p){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ", *(p+i*N+j));
        }
        printf("\n");
    }
}

int main(){
    int a[N][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    swap(a);
    print(a);
    
    // int i,j,t;
    // for(i=0;i<N;i++){
    //     for(j=i;j<N;j++){
    //         //printf("%d<->%d ", *(p+3*i+j),*(p+3*j+i));
    //         t = a[i][j];
    //         a[i][j] = a[j][i];//a[1] <-> a[3]
    //         a[j][i] = t;
    //         printf("%d<->%d ", a[i][j],a[j][i]);
    //     }
    // }

    // for(i=0;i<N;i++){
    //     for(j=0;j<N;j++){
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
}