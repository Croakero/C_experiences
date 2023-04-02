/*
思路：菜单函数提供循环输入功能并提供选择功能 
不要菜单函数了，直接在main()函数里提供菜单和循环输入 
创建一个结构数存储每个人的姓名和成绩， 
然后创建一个指针指向那个数组，给函数传入指针来通信。 
成绩排序排指针，用选择排序算法
二分查找不好办啊不好办。
*/

#include<stdio.h>
int records=0;
struct students{
	char name[10];
	int mark;
};
void sort(struct students*,const int );
void print(struct students*,const int );
int search(struct students*,const int );
int main(void){
	int selection;
	int numofstudents;
	struct students lists[20];//无可奈何，程序必须要读取1之后才会写入 
	struct students *ptr=&lists[0];
	scanf("%d",&selection);
	while(selection!=0){
		switch(selection){
			case 0:
				return 0;
			case 1:
				scanf("%d",&numofstudents);
				for(int i=0;i<numofstudents;i++){
					scanf("%s%d",&ptr->name,&ptr->mark);
					ptr++;
					records++;
				}
				printf("%d records were input!\n",records);
				ptr-=numofstudents;
				break;
			case 2:
				sort(ptr,numofstudents);
				printf("Reorder finished!\n");
				break;
			case 3:
				print(ptr,numofstudents);
				break;
			case 4:
				search(ptr,numofstudents);
		}
		scanf("%d",&selection);
	}
	return 0;
}

void sort(struct students *ptr,int numofstudents){
	struct students temp;
	for(int i=0;i<numofstudents;i++){
		for(int j=i;j<numofstudents;j++){
			if((ptr+i)->mark<(ptr+j)->mark){
				temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
			}
		}
	}
}

void print(struct students* ptr,const int numofstudents){
	for(int i=0;i<numofstudents;i++){
		printf("%s %d\n",ptr->name,ptr->mark);
		ptr++;
	}
}

int search(struct students*ptr,const int numofstudents){
	int marks;
	scanf("%d",&marks);
	int low=0,high=numofstudents-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(marks>(ptr+mid)->mark)
			high=mid-1;
		else if(marks<(ptr+mid)->mark)
			low=mid+1;
		else{
		printf("%s %d\n",(ptr+mid)->name,(ptr+mid)->mark);
		return 0;
		}
	}
	printf("not found!");
	return 0;
}
