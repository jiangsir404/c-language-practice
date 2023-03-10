// test_string.c
// 测试字符数组和字符操作函数
 
#include<stdio.h>
#include<string.h>

int main(){
	char s[] = {'h','e','l','l','o'};
	char s1[30] = "Hello";
	char s2[] = " World";
	
	//连接函数 
	printf("%s\n", strcat(s1,s2));
	
	// 长度函数，输出 hello 5 5  world 7 6 hello world 30 11
	printf("%s %d %d %s %d %d %s %d %d\n", s, sizeof(s), strlen(s), s2, sizeof(s2), strlen(s2), s1, sizeof(s1), strlen(s1));
	
	// 比较大小, 大于输出正整数 
	printf("%d ", strcmp(s1,s2)); 
	printf("%d\n", strcmp("hello","hello!"));

	//strcpy拷贝函数, cp2包括\0会覆盖cp1的前六个字符
	char cp1[]="beijing";
	char cp2[] = "china";
	printf("%d %s\n", strlen(strcpy(cp1,cp2)), cp1);
	
	//大小写转换函数  
	printf("%s %s\n", strupr(s1), strlwr(s2));
	
	return 0;
}
