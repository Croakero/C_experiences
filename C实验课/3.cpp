#include<stdio.h>
int main(void){
	unsigned long input,mask;
	while(scanf("%lu",&input)!=EOF){
	unsigned long mask1=0xff000000;
	for(int i=0;i<4;i++){
		long temp=(input&mask1)>>(8*(3-i));
		mask1=mask1/256;
		printf("%lu",temp);
		if(i<3)
			putchar('.');
	}
	putc('\n',stdout);
}
	return 0;
}
