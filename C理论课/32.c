#include<stdio.h>
#include<string.h>
#define SIZE 100
int main(void){
	FILE *fp;
	int i=1; 
	fp=fopen("assignment3.txt","w+");
	while(1){
		char temp[SIZE]={'\0'};
		fgets(temp,SIZE,stdin);
		if(strcmp(temp,"-END-\n")==0) break;
		char putin[strlen(temp)+1];
		strcpy(putin,temp);
		fprintf(fp,"%03d ",i);
		fputs(putin,fp);
		i++;
	}
	fclose(fp);
	fp=fopen("assignment3.txt","r");
	char temp[SIZE]={'\0'};
	for(int i=1;fgets(temp,SIZE,fp)!=NULL;i++){
		fputs(temp,stdout);
	}
	fclose(fp);
	return 0;
}
