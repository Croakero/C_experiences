#include<stdio.h>
#define SIZE 28
char* strnCat(const char s[],char t[],int n);
int main(void){
	char s[SIZE],t[SIZE];
	int n;
	scanf("%s %s %d",t,s,&n);
	char* t1=strnCat(s,t,n);
	return 0;
}

char* strnCat(const char s[],char t[],int n){
	int i=0,a;
	while(*(t+i)!='\0')
		i++;
	for(a=0;a<n;a++){
		*(t+a+i)=*(s+a);
	}
	for(int b=a+i;b<SIZE;b++){
		*(t+b)='\0';//ΪɶҪ���������ȫ��գ���Ҳ������������������ܡ� 
	}
	printf("%s",t);
	return t;
}
