#include<stdio.h>
int main(void){
	unsigned short int s;
	scanf("%hu",&s);
	unsigned short int s1=(s>>12)|(s<<12);
	s=s<<4;
	s=s>>8;
	s=s<<4;
	s=s|s1;
	printf("%hu",s);
	return 0;
}
