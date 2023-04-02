#include<stdio.h>
#include<stdlib.h>
int atoh(const char *nstr);
char *end=NULL;
int main(void){
	int n;
	char ar[20];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",ar);
		int atoh(ar);
	}
} 
int atoh(const char nstr){
	long number=0;
	number=strtol(nstr,NULL,16);
	printf("%d",number);
}
