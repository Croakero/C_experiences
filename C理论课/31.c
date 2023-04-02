 /* 分析比较两种实现方案的优劣，并在本题代码区顶部用注释的方式写出
 ...
 ...
 */
#include <stdio.h>
#include <stdlib.h>
struct data{
	char c;
	struct data* next;
};
struct data * delete_c(struct data *head,char input){
    struct data * current=head;
    struct data * prev=(struct data *)malloc(sizeof(struct data *));
	struct data *prev0=prev;
	prev->next=head;
	while(current!=NULL){
    	if(current->c==input){
    		struct data *temp=current;
    		current=current->next;
    		prev->next=current;
    		free(temp);
		}
		else{
			prev=current;
			current=current->next;
		}
    }
    struct data *temp=prev0->next;
    free(prev0);
    return temp;
}
int main()
{
    struct data *head=NULL,*current=NULL,*prev;
    char input;
    while((input=getchar())!='\n'){
    	current=(struct data*)malloc(sizeof(struct data));
    	if(head==NULL){
    		head=current;
		}
		else{
			prev->next=current;
		}
		current->c=input;
		current->next=NULL;
		prev=current;
	}
	input=getchar();
    head=delete_c(head,input);
    current=head;
    while(current!=NULL){
    	putchar(current->c);
    	struct data * temp=current;
    	current=current->next;
    	free(temp);
	}
    return 0;
}

