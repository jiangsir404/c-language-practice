/*
题目：有 n 个整数，使其前面各数顺序向后移 m 个位置，最后 m 个数变成最前面的 m 个数

思路:
1. 以空间换时间，用另一个数组存储移动的元素。
2. 原地Reverse逆置算法 Reverse(0,m),Reverse(m,n),Reverse(0,n);
*/

#include<stdio.h>

void Reverse(int a[], int l,int r){
    int i,j,t;
    //int *p = a+m;
    for(i=0;i<=(r-l)/2;i++){
        t = a[l+i];
        a[l+i] = a[r-i];
        a[r-i] = t;
    }
}

int main(){
    int a[20],b[20];
    int n,m,i,j;
    printf("pls input n m:");
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    //方法1: 用数组b完成后移的操作

    //先移动m-n位置的元素到b前m个位置
    for(i=m,j=0;i<n;i++,j++){
        b[j] = a[i];
    }
    //在把a数组中0-m-1位置的元素移动到b数组后面
    for(i=0;i<m;i++,j++){
        b[j] = a[i];
    }
    for(i=0;i<n;i++){

        printf("%d ", b[i]);
    }
    printf("\n");

    //方法二: 原地逆置算法
    Reverse(a,0,m-1);
    Reverse(a,m,n-1);
    Reverse(a,0,n-1);
    for(i=0;i<n;i++){

        printf("%d ", a[i]);
    }    
    return 0;
}