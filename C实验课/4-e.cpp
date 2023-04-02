//这个架构有问题，有问题，你不能用字符串，要用字符 

#include<stdio.h>
#include<string.h>
#define SIZE 50
void getandput(char *);
int main(void){
	char*ar[SIZE]={'\0'};
	for(int )
}

void getandput(char *temp){
	char* ptr
	for(int i=0;i<5;i++){
		fgets(temp,SIZE,stdin);
		for(1){
		if((ptr=strchr(temp,' '))!=NULL){
			if((ptr=strchr(ptr+1,' '))!=NULL){
				
			}
		}
		}
	}
}
char* s_gets(char *st,int n){
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);
	if(ret_val){
		find=strchr(st,'\n');
		if(find){
			*find='\0';
		}
		else while(getchar()!='\n');
	}
	return ret_val;
}


