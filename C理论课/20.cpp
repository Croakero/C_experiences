#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
�۲����������ˣ�ֱ�Ӱ���һ���ַ�ָ�룬allocһ��ֵ��Ȼ��ѭ����ȡ����realloc��ȡֱ������
���ˣ�temp1000�ַ����飬���õ��ڴ档 
������������������
�����������һ��1000��С�������� 
��currentָ�룬strstr���ң��ҵ��Ļ�strncat��cat���ָ����ϴ��ҵ�����λ��
���ָ���ƶ� strlenĿ�ĵ��ʵĳ��ȣ�Ȼ��strcpy���µ��ʸ��ŵ�Ŀ������棬current������ȡ
�ҵ��Ļ�strcat��---ѭ��
ֱ����ȡ��'\0'Ϊֹ 
*/

#define SIZE 1000
#define SSIZE 10
int main(void){
	char alter[SSIZE],target[SSIZE];
	scanf("%s%s",target,alter);
	FILE*fp=fopen("source.txt","r");
	char big[SIZE]={'\0'};//��ʱ��� 
	char towrite[SIZE]={'\0'};//׼�����ļ�д������� 
	fgets(big,SIZE,fp); //��������ȫ����ȡ���������������
	char *current=big,*find=NULL;//һ���䶯��һ��Ѱ��,��big���ƶ�
	char *currentw=towrite;//currentw��towrite���ƶ� 
	int step=0;//find�������߹��ĳ��� 
	while((find=strstr(current,target))!=NULL){
		step=find-current;
		strncat(currentw,find,step);//��Ŀ�ĵ���֮ǰ�ĸ��Ž�ȥ 
		currentw+=step;//currentw�ƶ�
		current+=strlen(target);//current����Ŀ�ĵ��� 
		strcat(currentw,alter); //currentw����д��ԭ����
		currentw+=strlen(alter);//currentw��д���µ��ʺ�Խ���µ��� 
	}
	//����Ҳ�������current����Ķ���ȫ����currentwд��ȥ 
	strcat(currentw,current);
	printf("%s",towrite);
	return 0;
}
