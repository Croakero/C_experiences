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
int number=0;
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
			scanf("%d%s%d%d%d%d",&current->number,&current->name,&current->E,&current->M,&current->P,&current->C);
			prev=current;
			prev->next=NULL;
			current->S=current->E+current->M+current->P+current->C;
		}
			printf("完成了%d位同学的成绩输入\n",n);
			number+=n;
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
					if(temp==0){
						choose(head,select);
					}
					else bubble(head,select);
				}
				else{
					if(temp==0){
						choose(head,select);
					}
					else{
						bubble(head,select);
					}
				}
				average(head); 
			break;
		}
		while(getchar()!='\n');
		scanf("%d",&select);
	}
	return 0;
}




void printeinfo(struct student *head){
	struct student * current=head;
	while(current!=NULL){
		printf("%d %s %d %d %d %d\n",current->number,current->name,current->E,current->M,current->P,current->C);
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
			printf("%d %s %d %d %d %d\n",current->number,current->name,current->E,current->M,current->P,current->C);
		}
		current=current->next;
	}
}

void average(struct student *head){
	struct student * current=head;
	while(current!=NULL){
		current->S=current->E+current->M+current->P+current->C;
		printf("%d %s %.2lf\n",current->number,current->name,(current->S)/4);
		current=current->next;
	}
}

void printainfo(struct student *head){
	struct student * current=head;
	while(current!=NULL){
		current->S=(current->E+current->M+current->P+current->C);
		printf("%d %s %d %.2lf\n",current->number,current->name,(int)current->S,(current->S)/4);
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

void bubble(struct student *head,int selection){
	char atempboi[10];
	struct student *current=head,*head0=head;
	struct student temp;
	double m=current->S;
	for(int i=0;i<number-1;i++){
		while(current->next!=NULL){
			if(selection==1){
				if(current->S<current->next->S){
		strcpy(atempboi,current->name);
		strcpy(current->name,current->next->name);
		strcpy(current->next->name,atempboi);
		current->C=current->C+current->next->C,current->next->C=current->C-current->next->C,current->C=current->C-current->next->C;
		current->M=current->M+current->next->M,current->next->M=current->M-current->next->M,current->M=current->M-current->next->M;
		current->P=current->P+current->next->P,current->next->P=current->P-current->next->P,current->P=current->P-current->next->P;
		current->E=current->E+current->next->E,current->next->E=current->E-current->next->E,current->E=current->E-current->next->E;
		current->S=current->S+current->next->S,current->next->S=current->S-current->next->S,current->S=current->S-current->next->S;
		current->number=current->number+current->next->number,current->next->number=current->number-current->next->number,current->number=current->number-current->next->number;
				}
			}
			else{
				if(current->S>=current->next->S){
		strcpy(atempboi,current->name);
		strcpy(current->name,current->next->name);
		strcpy(current->next->name,atempboi);
		current->C=current->C+current->next->C,current->next->C=current->C-current->next->C,current->C=current->C-current->next->C;
		current->M=current->M+current->next->M,current->next->M=current->M-current->next->M,current->M=current->M-current->next->M;
		current->P=current->P+current->next->P,current->next->P=current->P-current->next->P,current->P=current->P-current->next->P;
		current->E=current->E+current->next->E,current->next->E=current->E-current->next->E,current->E=current->E-current->next->E;
		current->S=current->S+current->next->S,current->next->S=current->S-current->next->S,current->S=current->S-current->next->S;
		current->number=current->number+current->next->number,current->next->number=current->number-current->next->number,current->number=current->number-current->next->number;
				}
			}
			current=current->next;
		}
		current=head0;
	}
}

void choose(struct student *head,int selection){
	char atempboi[10];
	struct student *current=head,*head0=head,*the_one=current;
	struct student temp;
	double m=current->S;
	for(int i=0;i<number-1;i++){
		current=head0;
		the_one=current;
		m=current->S;
		while(current!=NULL){
			if(selection==1){
				if(current->S>=m){
					the_one=current;
					m=the_one->S;
				}
			}
			else{
				if(current->S<=m){
					the_one=current;
					m=the_one->S;
				}
			}
			current=current->next;
		}
		current=head0;
		strcpy(atempboi,current->name);
		strcpy(current->name,the_one->name);
		strcpy(the_one->name,atempboi);
		current->C=current->C+the_one->C,the_one->C=current->C-the_one->C,current->C=current->C-the_one->C;
		current->M=current->M+the_one->M,the_one->M=current->M-the_one->M,current->M=current->M-the_one->M;
		current->P=current->P+the_one->P,the_one->P=current->P-the_one->P,current->P=current->P-the_one->P;
		current->E=current->E+the_one->E,the_one->E=current->E-the_one->E,current->E=current->E-the_one->E;
		current->S=current->S+the_one->S,the_one->S=current->S-the_one->S,current->S=current->S-the_one->S;
		current->number=current->number+the_one->number,the_one->number=current->number-the_one->number,current->number=current->number-the_one->number;
		head0=head0->next;
	}
}
