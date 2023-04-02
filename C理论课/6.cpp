#include<stdio.h>
#include<math.h>
int main(void){
	double n,sum=0;
	for(n=0;1/(2*n+1)>=1e-5;n++){
		sum+=pow(-1,n)*(1/(2*n+1));
	}
	printf("%f",sum*4);
}
