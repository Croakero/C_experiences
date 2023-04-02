/*
思路：
建立结构，内含一个学号，一个姓名，四个成绩和一个指针
开一个静态变量用来统计一共走过的项目数量 
main()函数循环读取菜单内容，switch语句分归五项，
③很有意思，读取一个字符串，然后有必要的话使用strtol函数 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int number;
struct student{
	int number;
	char name [10];
	int E,M,P,C;
	double S;
	struct student * next;
};
void getinfo(struct student *);
void printeinfo(struct student *);
void changeinfo(struct student *);
void average(struct student *);
void printainfo(struct student *);
void cleaninfo(struct student *);
void bubble(struct student *,int select);
void choose(struct student *,int select);
int main(void){
	struct student *head=NULL,*current=NULL;
	int select,n;
	scanf("%d",&select);
	while(select!=0){
		switch (select){
			case 0: cleaninfo(head);
			return 0;
			case 1: 	
		scanf("%d",&n);
		struct student * current,* prev;
		for(int i=0;i<n;i++){
			current=(struct student*)malloc(sizeof (struct student));
			if(head==NULL){
				head=current;	
			}
			else {
				prev->next=current;
			}
			scanf("%d%s%d%d%d%d",&current->number,&current->name,
			&current->E,&current->M,&current->P,&current->C);
			prev=current;
			prev->next=NULL;
		}
			printf("完成了%d位同学的成绩输入\n",n); 
			break;
			case 2: printeinfo(head);
			break;
			case 3: changeinfo(head);
			break;
			case 4: average(head);
			break;
			case 5: printainfo(head);
			break;
			case 6: scanf("%d",&select);
				int temp;
				if(select==0){
					scanf("%d",&temp);
					if(select==0){
						choose(head,select);
					}
					else bubble(head,select);
				}
				else{
					
				}
			break;
		}
		scanf("%d",&select);
	}
	
	return 0;
}

void getinfo(struct student *head){
	int n;
	scanf("%d",&n);
	struct student * current,* prev;
	for(int i=0;i<n;i++){
	current=(struct student*)malloc(sizeof (struct student));
	if(head==NULL){
		head=current;	
	}
	else {
		prev->next=current;
	}
	scanf("%d%s%d%d%d%d",&current->number,&current->name,&current->E,
	&current->M,&current->P,&current->C);
	prev=current;
	prev->next=NULL;
	}
	printf("完成了%d位同学的成绩输入\n",n); 
}

void printeinfo(struct student *head){
	struct student * current=head;
	while(current!=NULL){
		printf("%d %s %d %d %d %d\n",current->number,current->name,
		current->E,current->M,current->P,current->C);
		current=current->next; 
	}
}

void changeinfo(struct student *head){
	struct student * current=head;
	int find,num;
	char temp[10]={'\0'};
	scanf("%d%d",&find,&num);
	while(current!=NULL){
		if(current->number==find){
			switch(num){
				case 0:
				scanf("%s",current->name);
				break;
				case 1:scanf("%d",&current->E);
				break;
				case 2:scanf("%d",&current->M);
				break;
				case 3:scanf("%d",&current->P);
				break;
				case 4:scanf("%d",&current->C);
				break;
			}
			printf("%d %s %d %d %d %d\n",current->number,current->name,
			current->E,current->M,current->P,current->C);
		}
		current=current->next;
	}
}
void average(struct student *head){
	struct student * current=head;
	while(current!=NULL){
		current->S=current->E+current->M+current->P+current->C;
		printf("%d %s %.2lf\n",current->number,
		current->name,(current->S)/4);
		current=current->next;
	}
}
void printainfo(struct student *head){
	struct student * current=head;
	while(current!=NULL){
		current->S=(current->E+current->M+current->P+current->C);
		printf("%d %s %d %.2lf\n",current->number,
		current->name,(int)current->S,(current->S)/4);
		current=current->next;
	}
}
void cleaninfo(struct student *head){
	struct student *current=head,*temp;
	while(current!=NULL){
		temp=current->next;
		free(current);
		current=temp;
	}
}
