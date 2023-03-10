#include<stdio.h>
int main(){   
	int i;   
	if (fork() == 0) {   
	/* 子进程程序 */   
	for ( i = 1; i <1000; i ++ ) printf("This is child process/n");   
	}   
	else {   
	/* 父进程程序*/   
	for ( i = 1; i <1000; i ++ ) printf("This is process process/n");   
	}
	return 0;
}   
