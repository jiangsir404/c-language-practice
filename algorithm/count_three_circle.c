/*
有 n 个人围成一圈，顺序排号。从第一个人开始报数（从 1 到 3 报数），凡报到 3 的人退出
圈子，问最后留下的是原来第几号的那位

思路:
1. 给整个数组group进行排号1-n;
2. 每一次需要在排完一遍后从第一个人这里重复报数,直到只剩下一个人
3. 报数报到3后,应该要重头开始报数
4. 退出后可以将该数组元素设置为0，每次遍历时跳过。
5. 最后找到数组中那个值不为1的人即为留下来的最后的人。

*/

#include<stdio.h>
#define N 50

int main(){
    int group[N];
    int totalNum=0,restNum=0,count=0,roundcount=0;
    int i;
    scanf("%d", &totalNum);

    //初始化group为排号数字
    for(i=0;i<totalNum;i++){
        group[i] = i+1;
    }
    restNum = totalNum;
    //循环报数，知道只剩下最后一个人
    while(restNum>1){
        roundcount = 0; //遍历整个数组的计数器
        //第一轮遍历这个数组，进行报数，把报到3的人退出(设置group[i]=0)
        while(roundcount<totalNum){
            if(group[roundcount]!=0){
                count ++; //报数1-3
                if(count == 3){
                    //报3后退圈，剩余人数-1,重新报数1-3
                    group[roundcount] = 0;
                    restNum--;
                    count = 0;
                }
            }
            roundcount++;
        }
    }

    //输出group数组中值为1的那个数，即为最后留下的哪一位
    for(i=0;i<totalNum;i++){
        if(group[i] != 0){
            printf("the last num:%d", group[i]);
            break;
        }
    }
}