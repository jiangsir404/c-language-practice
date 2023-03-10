#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>



int main(int argc,char *argv[])
{
	int pid;
	pid = fork();
	printf("%d\n",pid);
	if(pid<0){
		fprintf(stderr,"Fork Failed");
		// exit(0);
	}else if(pid == 0){
		execlp("/bin/ls","ls",NULL);
	}else{
		wait(NULL);
		printf("Child Complete");
		// exit(0);
	}
}