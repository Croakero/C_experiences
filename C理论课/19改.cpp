#include<stdio.h>
#include<stdlib.h>
char *end=NULL;
int main(void){
	int n;
	long tmp[n];
	char ar[20];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",ar);
		tmp[i]=strtol(ar,NULL,16);
	}
	for(int a=0;a<n;a++){
		printf("%d ",tmp[a]);
	}
	return 0;
} 
