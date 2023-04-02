#include<stdio.h>
int main(void){
	int in,j=0;
	int ar[101],arb[100];
	for(int i=0;i<101;i++)
		ar[i]=(i+1)*(i+1);
	scanf("%d",&in);
	int i=0;
		for(int a=1;a<=100;a++){
			for(int b=1;b<=a;b++){
				if(ar[i]=a*a*10+b*b||ar[i]==a*a+b*b*10){
					arb[j]=ar[i];
					j++;
					putchar('a');
				}
			}
			i++;
			putchar('b');
		}

for(int i=0;in>arb[i];i++)
		printf("%d ",arb[i]);
	return 0;
}
