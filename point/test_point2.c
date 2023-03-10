// 测试行指针和指针数组

#include<stdio.h>
int main(){
    int a[3][4]={{1},{2},{3}},i,j;
    //测试行指针遍历二位数组
    int (*p)[4];
    p = a;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d", *(*(p+i)+j));
        }
    }
    printf("\n");
    
    //测试指针数组遍历二维数组
    char s[][10] = {"aaa", "bbb", "ccc"};
    char *p1[4];
    for(i=0;i<3;i++){
        p1[i] = s[i];
        printf("%s ", p1[i]);
    }

}