/*
˼·��
fopen()���ļ���Ȼ����fgets����һ��һ��д�룬
��һ����һ������鱣֤ÿ�в�Խ�硣(�����ڻ��������ȡ��ŶҮ)
Ҫ��strstr()���������Ȳ���Ŀ�굥�ʣ�
������صĲ��ǿ�ָ��Ļ�����ô�������ң�����ҵ��Ļ���
��ӡǰ������ݣ�Ȼ�� 
���ܾ�����������ܱ�׾�������ں������ҿ��ܴ������Ұ�ָ�� �� 
��û�д�ӡ��ָ��ָ��λ�õĺ�������ֻ��Ҫ��û�õı��'\0'�ͳ��ˣ�ok 
�ޣ���strncopy()����,�Ǹ�����n������ָ������ó�����
���Ǹ���ǰ�������ȫ������strncpy�������Ƶ�ĳ����temp��
��������ָ�����ƶ��Ǹ��ַ����ĳ��ȣ�Ȼ����Ų���
*/

#include<string.h>
#include<stdio.h>
#define SIZE 100
int main(void){
	char read[SIZE]={'\0'};//���ļ���ȡһ������ 
	char target[10]={'\0'};//Ŀ��ʻ� 
	char source[10]={'\0'};//ԭʼ�ʻ� 
	FILE *fp;//���ļ� 
	fp=fopen("source.txt","r+");
	
	while(1){
		char temp[SIZE]={'\0'};
		if(fgets(temp,SIZE,fp)==NULL) break;
		char putin[strlen(temp)+1];
		strcpy(putin,temp);//����putin������������ش洢������Ҫ�Ķ��� 
		char *find=NULL;
		char *anchor;//ê�㣬�����ƶ�����λ�� 
		while((find=strstr(putin,source)))
	}
} 
