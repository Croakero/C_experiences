#include<stdio.h>
int ismtx(int[][5]);
int main(void){
	int ar[5][5];
	for(int a=0;a<5;a++){
		for(int b=0;b<5;b++){
			scanf("%d",&ar[a][b]);
		}
	}
	int bl=ismtx(ar);
	printf("%d",bl);
	return 0;
}

int ismtx(int mx[][5]){
	int num=0;
	for(int a=0;a<5;a++){
		for(int b=0;b<5;b++){
			if(a==b){
				if(mx[a][b]==1)
				num++;
			}
			else if(mx[a][b]==0)
				num++;
		}
	}
	if(num==25)
		return 1;
	else 
		return 0;
}
