 #include <stdio.h>
 int main(void)
 {
     int i=getchar();
	 if(i>='0'&&i<='9')
	 	putchar(i);
	else if(i>='a'&&i<='f')
		printf("%d",i-87); 
	else if(i>='A'&&i<='F')
		printf("%d",i-55);
	else
		putchar(i);
		return 0; 
 }
