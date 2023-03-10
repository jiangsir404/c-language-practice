#include<stdio.h>
int main(){
	char *s = "hello,world";
	FILE * fp;
	if(!(fp=fopen("hello.txt","w"))){
		printf("failed");
	}else{
		fputs(s,fp);
		printf("write success!");
	}
}
