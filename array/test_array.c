// test_array

#include<stdio.h>
#define N 3

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

//用二维数组中函数参数，必须制定大小，或者用int(*a)[N]
void print2(int a[][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

//用指针输出二位数组
void print3(int a[][N]){
    int *p;
    for(p=a[0];p<a[0]+N*N;p++){
        printf("%d ", *p);
    }
}

int main(){
    //输出二维数组
    int a[N][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    print(a);
    print2(a);
    print3(a);
    return 0;
}