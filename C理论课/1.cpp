 #include <stdio.h>
 #include<ctype.h> 
 int main(void)
 {
     int i=getchar();
     switch(i){
	 case 'a':
	case 'A':
		printf("10");
		return 0;
	case 'b':
	case 'B':
		printf("11");
		return 0;
	case 'c':
	case 'C':
		printf("12");
		return 0;
	case 'd':
	case 'D':
		printf("13");
		return 0;
	case 'e':
	case 'E':
		printf("14");
		return 0;
	case 'f':
	case 'F':
		printf("15");
		return 0;
	 }
	 if(i>='0'&&i<='9')
	 	{
		 putchar(i);
		 return 0;
	}
	if(isalpha(i));
		putchar(i); 

 }
