/*
思路：
复用第十八关的数组类似思想，无冗余存储，我喜欢这样
开一个简单字符串temp，SIZE设置一下
开一个指针数组，malloc分配空间一个指针大小
********↓ 
scanf能读到东西则循环读取，开一个循环
读取到内容存到temp里面，然后我需要做两件事情
指针数组分配一个新元素，需要一个计数器 
新元素分配内存，把temp里的东西存到它里面，
然后清空temp 
哈哈，我突然想到那个隐藏的问题，你会循死都读不到东西，弃用这个思路
或者整点有意思的，在每次scanf之后都getchar一下(未采用此思路)
**********
换的新思路 
我要是用getchar()的话 
c不是换行的时候，如果c是空格(注意处理头元素) 
realloc让指针数组多一个元素，需要一个计数器(这步卡住了)
所以需要新思路，我用链表读取，再把链表元素给数组 
分配多出来的那个元素
多出来的那个元素循环读取 
********
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
char * find(char *a[],int);
struct data{
	char *c;
	struct data *next;
}; 
int main(void){
	char temp[SIZE]; 
	int i=0,inword=0,count=0;
	struct data *head=(struct data *)malloc(sizeof(struct data)),*current=head;
	for(char c=getchar();c!='\n';c=getchar()){
		if(c!=' '){//如果c不是空格
			temp[i]=c;
			i++;
		}
		else if(c==' '){//如果c是空格 
			current->c=(char *)malloc(i*sizeof(char)+1);
			strncpy(current->c,temp,i);
			current->c[i]='\0';//造一个字符串出来 
			i=0;
			current->next=(struct data *)malloc(sizeof(struct data));//current后移前给空间 
			current=current->next; 
			count++;
		}
	}//值得注意的是此时最后一个字符串没造出来
	current->c=(char *)malloc(i*sizeof(char)+1);
	strncpy(current->c,temp,i);
	current->c[i]='\0';//造一个字符串出来 
	i=0;
	current->next=NULL; 
	count++;
	char *a[count];
	current=head;
	for(int i=0;i<count;i++){
		a[i]=current->c;
		current=current->next;
		//puts(a[i]);目前一切正常 
	}
	char *the_one=find(a,count);
	printf("%s %d",the_one,strlen(the_one));
	for(current=head;current!=NULL;){
		struct data *temp;
		temp=current;
		current=current->next;
		free(temp);
	}
	//别忘了把malloc的东西全部给free掉 
	return 0;
} 

char *find(char *a[],int n){
	char *max=a[0];
	for(int i=0;i<n;i++){
		if(strlen(max)<strlen(a[i]))
		max=a[i];
	}
	
	return max;
}
