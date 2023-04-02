#include<stdio.h>
void swap(int *ar,int n);
int main(void){
	int n;
	scanf("%d",&n);
	int ar[n+1];
	for(int a=0;a<n;a++){
		scanf("%d",ar+a);
	}
	swap(ar,n);
	for(int a=1;a<n+1;a++){
		printf("%d ",*(ar+a));
	}
	return 0;
}

void swap(int *ar,int n){
	int temp;
	for(int a=0;a<n/2+1;a++){
		temp=*(ar+a);
		*(ar+a)=*(ar+n-a);
		*(ar+n-a)=temp;
	}
}
