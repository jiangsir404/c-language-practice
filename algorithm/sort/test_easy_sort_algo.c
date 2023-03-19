//简单排序算法

#include<stdio.h>
#define ElemType char

//冒泡排序
void bubble_sort(ElemType a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                ElemType t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

//选择排序
void select_sort(ElemType a[], int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j] < a[min]) min = j;
        }
        // 不能写成min==j,因为退出for循环后j++了。
        if(min!=i){
            ElemType t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
}

//插入排序
void insert_sort(ElemType a[], int n){
    int i,j;
    for(i=2;i<n;i++){
        //逆序
        if(a[i-1]>a[i]){
            a[0] = a[i];
            //循环条件依旧是逆序的情况
            for(j=i-1;a[j]>a[0];j--){
                a[j+1] = a[j];//往后移动
            }
            a[j+1] = a[0];//退出循环后j多减了1
        }
    }
    return ;
}

int main(){
    //测试冒泡排序
    char a[7] = {'1','5','4','3','2','6','\0'};
    puts(a);
    bubble_sort(a, strlen(a));
    printf("bubble_sort output:%s\n", a);

    //测试选择排序
    char b[] = {"helloworld"};
    select_sort(b, strlen(b));
    printf("select_sort output:%s\n", b);

    //测试选择排序
    char c[] = {"helloworld"};
    select_sort(c, strlen(c));
    printf("insert_sort output:%s", c);
    return 0;
}