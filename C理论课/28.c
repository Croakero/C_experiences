#include<stdio.h>
#include<string.h>
#define USIZE 30
#define SSIZE 30
#define QSIZE 30 
struct web{
	char s[SSIZE];
	char q[QSIZE];
	char u[USIZE];
};
int main(void){
	int number;
	scanf("%d",&number);
	struct web all[number];
	for(int i=0;i<number;i++){
		scanf("%s%s%s",&all[i].u,&all[i].s,&all[i].q);
		while(getchar()!='\n'); 
	}
	struct web temp;
	for(int j=0;j<number-1;j++)
	for(int i=0;i<number-1;i++){
		if(strcmp(all[i].s,all[i+1].s)>0){
			temp=all[i];
			all[i]=all[i+1];
			all[i+1]=temp;
		}
	}
	for(int i=0;i<number;i++){
		printf("%s %s %s\n",all[i].u,all[i].s,all[i].q);
	}
	char temps[SSIZE];
	scanf("%s",temps);
	for(int i=0;i<number;i++){
		if(strcmp(temps,all[i].s)==0){
			printf("%s\n",all[i].u);
		}
	}
	return 0;
}
