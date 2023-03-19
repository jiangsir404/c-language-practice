//测试fread(buff,size,count,fp)和fwrite(buff,size,count,fp)的用法

#include<stdio.h>

struct student {
    char *num;
    char *name;
    int score[3];
}stu = {"101", "jiangsir", {77,77,88}};

int main(){
    //printf("%s", stu.name);
    //测试fwrite写入结构体到文件
    FILE *fp;
    fp = fopen("stu.txt", "wb");
    fwrite(&stu,sizeof(struct student), 1, fp);
    fclose(fp);
    //测试fread读取二进制文件。
    fp = fopen("stu.txt", "rb");
    struct student stu1;
    fread(&stu1,sizeof(struct student), 1, fp);
    printf("stu info: %s %s %d %d %d", stu1.num,stu1.name,stu1.score[0],stu1.score[1],stu1.score[2]);

    return 0;
}