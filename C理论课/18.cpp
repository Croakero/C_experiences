#include <stdio.h>
//有无用代码，但是现在管不了那么多。 
int i1,i2;/*这里i1是t的长度，i2是s的长度*/
void strnCpy(char s[], const char t[], int n)
{
	if(i1<=n){
		for(int a=0;a<i1;a++){
			s[a]=t[a];
		}
	}
	else 
		for(int b=0;b<n;b++){
		s[b]=t[b];
	}
	printf("%s",s);
}
int main(void)
{	
	int n;
	char t0[100],s0[100];
	scanf("%s",s0);
	scanf("%s",t0);
	scanf("%d",&n);
	//很棘手，这个很棘手，未定长度的数组会惹大麻烦printf("%d %d",sizeof t0,sizeof s0);
	for(i1=0;t0[i1]!='\0';i1++);
	//printf("\n%d",i1);
	for(i2=0;s0[i2]!='\0';i2++);
	//printf("\n%d",i2); 
	strnCpy(s0,t0,n);
	return 0;
}
