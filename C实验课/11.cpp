#include<stdio.h>
#include<limits.h>
int main(void){
	int input;
	scanf("%d",&input);
	int n=sizeof(int)*CHAR_BIT;
	int mask=1;
	char ar [n+1]={'\0'};
	mask=mask<<(n-1);//����Ų�������ۿ���Ŀ������
	for(int i=0;i<n;i++){
		ar[i]=(input&mask)?'1':'0';
		input<<=1;
	}
	printf("%s",ar);
}
