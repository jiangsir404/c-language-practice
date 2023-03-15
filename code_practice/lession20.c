/*
从3个红球，5个白球，6个黑球中任取8个球，其中必须有白球，输出所有可能的方案

思路：穷举法: 三重循环递归遍历，白球从1开始。
用if条件i+j+k==8来筛选。
*/

#include<stdio.h>

int main(){
    int i,j,k;
    for(i=0;i<=3;i++){
        for(j=1;j<=5;j++){
            for(k=0;k<=6;k++){
                if(i+j+k==8){
                    printf("%d %d %d\n", i,j,k);
                }
            }
        }
    }
    return 0;
}