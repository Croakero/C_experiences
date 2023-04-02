/*
思路：
通过指针取出每字节的操作通过声明指向char的指针实现 
真是绝妙的主意 
*/

#include<stdio.h>

int main(void){
	long l;
	scanf("%ld",&l);
	char* ptr=(char*)&l;
	ptr+=3;
	int i;
	for(i=0;i<4;i++){
		char temp=*ptr;
		printf("%X",(*ptr>>4)&15);
		printf("%X",(*ptr)&15);
		ptr--;
	}
	return 0;
}
