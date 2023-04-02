#include<stdio.h>
int main(void){
	int a,b,c,d;
	int min,mod;
	scanf("%d %d",&a,&b);
	c=a,d=b;
	for(mod=1;mod!=0;){
		if(a>=b){
			mod=a%b;
			if(mod!=0)
			a=mod;}
		else{
			mod=b%a;
			if(mod!=0)
			b=mod;
		}
	}
	mod=a>b?b:a;
	min=c*d/mod;
	printf("%d %d",mod,min);
}
