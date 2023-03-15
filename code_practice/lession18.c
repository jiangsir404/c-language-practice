/*
题目：编写input()和output()函数输入，输出5个学生的数据记录。
struct student
{ char num[6];
　char name[8];
　int score[4];
} stu[N];
*/

#include<stdio.h>
#define N 5


struct student
{
    char num[6];
    char name[8];
    int score[3];
}stu[N];

void input(struct student stu[]){
    int i,j;
    printf("pls input student info:\n");
    for(i=0;i<N;i++){
        printf("num:");
        scanf("%s", stu[i].num);
        printf("name:");
        scanf("%s", stu[i].name);
        for(j=0;j<3;j++){
            printf("score %d:", j+1);
            scanf("%d", &stu[i].score[j]);
        }
    }
}

/*
输出方式：
num     name    s1      score2  score3
101     aa      88      88      88
102     bb      77      77      77
*/
void output(struct student stu[]){
    int i,j;
    printf("num\tname\tscore1\tscore2\tscore3\n");
    for(i=0;i<N;i++){
        printf("%s", stu[i].num);
        printf("\t%s", stu[i].name);
        for(j=0;j<3;j++){
            printf("\t%d", stu[i].score[j]);
        }
        printf("\n");
    }
}

int main(){
    input(stu);
    output(stu);
    return 0;
}