// 给出百分制成绩，要求输出成绩等级'A','B','C','D','E' 
// 90分以上为'A',80-89分为'B',60-69分为'D',60分以下为'E'

#include<stdio.h>

void main(){
    float score;
    char grade;
    printf("please input student score:");
    scanf("%f", &score);
    // 通过(int)(score/10)的方式和case进行比较
    switch((int)(score/10)){
        case 10:
        case 9:grade = 'A';break;
        case 8:grade = 'B';break;
        case 7:grade = 'C';break;
        case 6:grade = 'D';break;
        default: grade = 'E';
    }
    printf("score:%5.2f, grade:%c\n", score,grade);
}