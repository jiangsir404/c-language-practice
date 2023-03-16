/*
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？


思路：穷举法，可填在百位、十位、个位的数字都是1、2、3、4。
组成所有的排列后再去掉不满足条件的排列。

4*3*2=24种
*/

#include<stdio.h>
void main(){
    int i,j,k,count=0;
    for(i=1;i<5;i++){
        for(j=1;j<5;j++){
            for(k=1;k<5;k++){
                if(i!=j && j!=k && k!=i){
                    printf("%d%d%d ", i,j,k);
                    count += 1;
                }
            }
        }
    }
    printf("\nsum count:%d", count);
}

