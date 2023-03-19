//测试fputs(buf,fp)和fgets(buf,n,fp)的用法

#include<stdio.h>
int main(){
	char *s = "hello,world";
	FILE * fp;
	if(!(fp=fopen("hello.txt","w"))){
		printf("failed");
	}else{
		fputs(s,fp);
		printf("write success!\n");
	}
	fp = fopen("hello.txt", "r");
	fgets(s, strlen(s)+1, fp);
	printf("read file:%s", s);
}
