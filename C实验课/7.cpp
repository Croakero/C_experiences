#include<stdio.h>
#define SIZE 10000
int gold(int);
int main(void){
	int i;
	while(scanf("%d",&i)!=EOF){
	if(i>=4&&!(i%2))
	gold(i);
}
	return 0;
}

int gold(int i){//生成部分 
	int arr[SIZE]={2,3};
	int num=2;
	int k; 
	for(int j=5;num<SIZE;j++){
		for(k=3;k<j;k++){
			if(j%k);
			else break;
			if(k==j-1){
			arr[num]=j;
			num++;
			}
		}
	}
	for(int m=0;arr[m]<i;m++){
		for(int n=0;arr[n]<i;n++){
			if(i==arr[m]+arr[n]){
				printf("%d=%d+%d\n",i,arr[m],arr[n]);
				return 0;
			}
		}
	}
}
