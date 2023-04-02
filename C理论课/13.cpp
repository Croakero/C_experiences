#if(0)
#include<stdio.h>
int main(void){
	int i=1,j=1;
	int count=2;
	int in;
	scanf("%d",&in);
	while(count<in){
		if(i>=j){
			j=i+j;
		}
		else if(i<j){
			i=i+j;
		}
		count++;
	}
	int temp=i>j?i:j;
	printf("%d",temp);
	return 0;
}
#endif
//以下是测试代码 
#if(1) 

#include<stdio.h>
int main(void){
	int i=1,j=1;
	int count=2;
	int in=45;
	while(count<in){
		if(i>=j){
			j=i+j;
		}
		else if(i<j){
			i=i+j;
		}
		count++;
	}
	int temp=i>j?i:j;
	printf("%d",temp);
	return 0;
}
#endif
