#include<stdio.h>
int main(void){
	int ar[10];
	int flag;
	for(int i=0;i<10;i++)
		scanf("%d",&ar[i]);
	for(int a=0;a<10;a++){
		if(ar[a]>=10000)
			flag++;
		else if(!(ar[a]%7)){
			if(ar[a]>=1000&&ar[a]/1000==5)
				printf("%d ",ar[a]);
			else if(ar[a]>=100&&!((ar[a]/100)%5))
				printf("%d ",ar[a]);
			else if(ar[a]>=10&&!((ar[a]/10)%5))
				printf("%d ",ar[a]);
			else if(!(ar[a]%5)&&ar[a]%10)
				printf("%d ",ar[a]);
			else flag++;
		}
		else
			flag++;
	}
	if(flag==10)
		putchar('0');
	return 0;
}
