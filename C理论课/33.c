/*
˼·��
������һ���ļ�ָ�룬���ļ���Ȼ����getc()���ж�
�ַ�������isalnum()���жϣ����isinword==0ʱ�����ո����ispunct��
��ôisinword���1��(�տ�ʼisinwordҪ����Ϊ1)�����
isinword==1��ʱ�������ո����ispunct����������Ϊ0��������+1
��������˾�ţ���ô����+1������ж�Ӧ���Ƕ������ж� 
��ʼ�� 
*/
#include<ctype.h>
#include<stdio.h>

int main(void){
	char c,prev;
	int inword=0,characters=0,words=0,sentences=0;
	int out=0;
	FILE *fp;
	char temp[40]={'\0'};
	scanf("%s",temp);
	fp=fopen(temp,"r");
	while((c=getc(fp))!=EOF){
		out++;
		if(!isspace(c)&&!inword){//����ǿհ��ַ�����û�ڵ����� 
			inword=1;
			words++;
		}
		if(isspace(c)&&inword){//����ǿհ��ַ������ڵ����ڣ����ʽ��� 
			inword=0;
		}
		if(c=='.'){
			sentences++;
		}
		if(isspace(c)){
			characters++;
		}
	}
	characters=out-characters;
	fclose(fp);
	printf("Characters: %d\n",characters);
	printf("Words: %d\n",words);
	printf("Sentences: %d",sentences);
	return 0;
}

