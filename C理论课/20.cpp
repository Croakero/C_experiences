#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
咱不各美其美了，直接安排一个字符指针，alloc一个值，然后循环读取，再realloc读取直到读完
算了，temp1000字符数组，多用点内存。 
暴力，暴力就完事了
给这个大数组一个1000大小的新数组 
用current指针，strstr查找，找到的话strncat，cat这个指针和上次找到相差的位置
这个指针移动 strlen目的单词的长度，然后strcpy把新单词给放到目标的里面，current继续读取
找到的话strcat到---循环
直到读取到'\0'为止 
*/

#define SIZE 1000
#define SSIZE 10
int main(void){
	char alter[SSIZE],target[SSIZE];
	scanf("%s%s",target,alter);
	FILE*fp=fopen("source.txt","r");
	char big[SIZE]={'\0'};//暂时存放 
	char towrite[SIZE]={'\0'};//准备往文件写入的内容 
	fgets(big,SIZE,fp); //现在内容全部读取到了这个大数组里
	char *current=big,*find=NULL;//一个变动，一个寻找,在big中移动
	char *currentw=towrite;//currentw在towrite中移动 
	int step=0;//find到现在走过的长度 
	while((find=strstr(current,target))!=NULL){
		step=find-current;
		strncat(currentw,find,step);//把目的单词之前的给放进去 
		currentw+=step;//currentw移动
		current+=strlen(target);//current跳过目的单词 
		strcat(currentw,alter); //currentw里面写入原单词
		currentw+=strlen(alter);//currentw在写入新单词后越过新单词 
	}
	//如果找不到，将current后面的东西全部给currentw写进去 
	strcat(currentw,current);
	printf("%s",towrite);
	return 0;
}
