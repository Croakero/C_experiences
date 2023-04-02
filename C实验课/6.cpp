#include<stdio.h>
#include<math.h>
int main(void){
	for(int i=100;i<1001;i++){
		int temp=pow(i,2);
		if(temp%1000==i)
		printf("%d\n",i);
	}
	return 0;
}
