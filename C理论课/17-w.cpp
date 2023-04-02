#include<stdio.h>
#include<ctype.h>
int main(void){
	int count[3]={0,0,0};
	char ch;
	while((ch=getchar())!='\n'){
		if(isalpha(ch)){
			count[1]++;
		}
		else if(isdigit(ch)){
			count[0]++;
		}
		else if(ispunct(ch))
			count[2]++;
		else
			break;
	}
	printf("%d %d %d",count[0],count[1],count[2]);
}
// 这个有问题，判断字符结束的方法有问题 
