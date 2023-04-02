#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++){
		scanf(" %d",&ar[a]);
	}
	int temp;
	for(int b=0;b<n-1;b++){
		int min=b;
		for(int c=b+1;c<n;c++){
			if((*(ar+c))>(*(ar+min))){
				min=c;
			}	
			}
			if(min!=b){
				temp=(*(ar+min));
				(*(ar+min))=(*(ar+b));
				(*(ar+b))=temp;
		}
	}
	
	for(int d=0;d<n;d++){
		printf("%d ",ar[n-d-1]);
	}
} 
