#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
extern int errno;

// int main(int argc,char* argv[]){
// 	;
// 	return 0;
// }
int main(){
	// int num = 6666666;
	// printf("before:num = %d\n",num);
	// printf("%d%n\n",num,&num);
	// printf("After: num = %d\n",num);

	int a;
	char buf[100];
	a = read(1,buf,100);
	printf("a=%d\n",a);
}