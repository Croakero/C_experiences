#include <stdio.h>
//�����ô��룬�������ڹܲ�����ô�ࡣ 
int i1,i2;/*����i1��t�ĳ��ȣ�i2��s�ĳ���*/
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
	//�ܼ��֣�����ܼ��֣�δ�����ȵ�������Ǵ��鷳printf("%d %d",sizeof t0,sizeof s0);
	for(i1=0;t0[i1]!='\0';i1++);
	//printf("\n%d",i1);
	for(i2=0;s0[i2]!='\0';i2++);
	//printf("\n%d",i2); 
	strnCpy(s0,t0,n);
	return 0;
}
