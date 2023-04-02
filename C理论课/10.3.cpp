#include<stdio.h>
#include<math.h>
int main(void){
	unsigned long long count,number,input2,erdemi;
	int input1;
	scanf("%d %lld",&input1,&input2);
	erdemi=pow(2,input1-1);
	while(erdemi>=1){
		if(input2/erdemi==1)
			putchar('1');
		else putchar('0');
		input2=input2%erdemi;
		erdemi=erdemi/2;
	}
	return 0;
}
