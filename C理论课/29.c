/*
思路：
首先建立结构，内含一个字符变量，一个指针，计数器之后再说
然后用读取非回车作为循环判断条件，内部构建链表
读取完毕后分配一个计数器大小的字符数组，最后再输出之 
*/ 
#include<stdio.h>
#include<stdlib.h>
struct data{
	char c;
	struct data *next;
};

int main(void){
	struct data *current,*prev,*head=NULL;
	char ch;//临时存储字符 
	int count=0;//计数器 
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
