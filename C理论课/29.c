/*
˼·��
���Ƚ����ṹ���ں�һ���ַ�������һ��ָ�룬������֮����˵
Ȼ���ö�ȡ�ǻس���Ϊѭ���ж��������ڲ���������
��ȡ��Ϻ����һ����������С���ַ����飬��������֮ 
*/ 
#include<stdio.h>
#include<stdlib.h>
struct data{
	char c;
	struct data *next;
};

int main(void){
	struct data *current,*prev,*head=NULL;
	char ch;//��ʱ�洢�ַ� 
	int count=0;//������ 
	while((ch=getchar())!='\n'){
		count++;
		current=(struct data*)malloc(sizeof(struct data));
		if(head==NULL){
			head=current;
		}
		else{
			prev->next=current;
		}
		current->c=ch;
		current->next=NULL;
		prev=current;
	}
	current=head;
	for(int i=0;i<count;i++){
		printf("%c",current->c);
		current=current->next;
	}
	putchar('\n');
	current=head;
	char *output=(char*)malloc(sizeof(char)*count);
	for(int i=0;i<count;i++){
		output[i]=current->c;
		head=current->next;
		free(current);
		current=head;
	}
	printf("%d\n%s",count,output);
	return 0;
}
