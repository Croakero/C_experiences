#include<stdio.h>
int main(void){
	int i,temp;
	scanf("%d",&i);
	int ar[i];
	for(int num=0;num<i;num++)
		scanf("%d",&ar[num]);
	for(int a=0;a<i;a++){
		for(int b=i-1;b>=a;b--){
			temp=ar[b];
			if(ar[b]>=ar[b-1]);
			else{
				ar[b]=ar[b-1];
				ar[b-1]=temp;
			}
		}
	}
	for(int num=0;num<i;num++){
		printf("%d ",ar[num]);
	}
	return 0;
}
