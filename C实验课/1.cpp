#include<stdio.h>
#include<ctype.h>
int main(void){
	char c;
	while((c=getchar())!=EOF){
		if(isupper(c))
			putchar(tolower(c));
		else putchar(c);
	}
}
