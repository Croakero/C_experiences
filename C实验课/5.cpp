/*
һ�������ӡǰ��Ŀո�һ�������ӡ�ַ�
��������������һ��������һ����0��ʼ���� 
*/

#include<stdio.h>
int main(void){
	int i,j,temp;//i���ƿո�j��������ѭ����temp����ֵ 
	scanf("%d",&i);
	int number=2*i+i;
	for(int m=0;m<number;m++){
		putchar(' ');
	}
	printf("1   \n");
	for(int k=1;k<=i;k++){
		temp=1;
		number-=2;
		for(int m=0;m<number;m++)
			putchar(' ');
		for(j=1;j<=k+1;j++){
			if(temp/100)
			printf("%d ",temp);
			else if(temp/10)
			printf("%d  ",temp);
			else printf("%d   ",temp);
			temp=temp*(k-j+1)/j;
		}
		putchar('\n');
	}
	return 0;
}
