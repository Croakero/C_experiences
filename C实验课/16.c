/*
˼·��
ͨ��ָ��ȡ��ÿ�ֽڵĲ���ͨ������ָ��char��ָ��ʵ�� 
���Ǿ�������� 
*/

#include<stdio.h>

int main(void){
	long l;
	scanf("%ld",&l);
	char* ptr=(char*)&l;
	ptr+=3;
	int i;
	for(i=0;i<4;i++){
		char temp=*ptr;
		printf("%X",(*ptr>>4)&15);
		printf("%X",(*ptr)&15);
		ptr--;
	}
	return 0;
}
