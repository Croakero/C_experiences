#include<stdio.h>
void gnirts(void);
int main(void){
	gnirts();
	return 0;
}

void gnirts(void){
	char ch=getchar();
	if(ch!='\n'){
	gnirts();
	}
	putchar(ch);
}
