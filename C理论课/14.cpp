#include<stdio.h>
#define swap(x,y) x=x+y,y=x-y,x=x-y;
int main(void){
	int x,y;
	scanf("%d %d",&x,&y);
	swap(x,y);
	printf("%d %d",x,y);
	return 0;
}
