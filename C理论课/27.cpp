#include<stdio.h>

void getinfo(struct student *);
void ptrshowinfo(struct student *ptr);
void showinfo(struct student);
struct student{
	int num;
	char name[12];
	int score;
};
int main(void){
	int n;
	scanf("%d",&n);
	struct student stds[n];
	struct student* ptr=&stds [n-1];
	for(int i=0;i<n;i++){
		getinfo(ptr);
		ptr--;
	}
	for(int i=0;i<n;i++){
		showinfo(stds[n-i-1]);
	}
	ptr++;
	for(int i=0;i<n;i++){
		ptrshowinfo(ptr);
		ptr++;
	}
	return 0;
}

void getinfo(struct student *ptr){
	scanf("%d%s%d",&ptr->num,&ptr->name,&ptr->score);
}

void ptrshowinfo(struct student* ptr){
	fprintf(stdout,"%d %s %d\n",ptr->num,ptr->name,ptr->score);
}

void showinfo(struct student stds){
	fprintf(stdout,"%d %s %d\n",stds.num,stds.name,stds.score);
}
