// 编写一个input,print函数，用来输入输出5个学生的数据记录
//并且计算出五个学生的平均成绩保持到文件中。

#include<stdio.h>

#define N 5

struct student {
    char num[6];
    char name[8];
    int score[4];
    float ave;
}stu[N];

int main(){
    // input(stu);
    // print(stu);
    // save_stu_into_file(stu);
    read_stu_from_file();
    return 0;
}

void input(struct student stu[]){
    int i,j,sum;
    for(i=0;i<N;i++){
        printf("input socres of stduent %d:\n", i+1);
        printf("num:");
        scanf("%s", stu[i].num);
        printf("name:");
        scanf("%s", stu[i].name);
        sum = 0;
        for(j=0;j<3;j++){
            printf("score%d:", j+1);
            scanf("%d", &stu[i].score[j]);
            sum += stu[i].score[j];
        }
        stu[i].ave = sum / 3.0;
        printf("\n");
    }
}

void print(struct student stu[6]){
    int i,j;
    printf("\n num name score1 score2 score3 ave\n");
    for(i=0;i<N;i++){
        printf("%5s%10s", stu[i].num,stu[i].name);
        for(j=0;j<3;j++){
            printf("%9d", stu[i].score[j]);
        }
        printf("%9f", stu[i].ave);
        printf("\n");
    }
}

void save_stu_into_file(struct student stu[6]){
    int i,j;
    FILE *fp;
    if((fp=fopen("stu.txt", "wb"))==NULL){
        printf("The file can not open\n");
        return ;
    }
    for(i=0;i<5;i++){
        //二进制读写方式可以直接读写一个结构体
        fwrite(&stu[i],sizeof(struct student),1,fp);
    }
    
}

void read_stu_from_file(){
    int i;
    FILE *fp;
    if((fp=fopen("stu.txt","rb"))==NULL){
        printf("read file fail");
        return ;
    }
    for(i=0;i<N;i++){
        fread(&stu[i],sizeof(struct student),1,fp);
        printf("%s %7s %7d %7d %7d %8.2f\n",stu[i].num,stu[i].name,
        stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
    }
}
