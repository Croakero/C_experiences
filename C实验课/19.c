/*
思路：
八个函数，main里面调用scheduler函数，scheduer循环读取 
字符，在这之前先整一个函数指针数组，
元素指向返回值和形参都是void的函数 
然后每次循环前realloc一下，(为啥我realloc不行了)得开大数组 
这样数组里就按顺序存储了需调度的函数
然后把这个数组和任务个数传递给execute函数，execute函数里
开一个循环，然后调用每一个元素对应的函数。 
*/


#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void task0(void){
	puts("task0 is called!");
}
void task1(void){
	puts("task1 is called!");
}
void task2(void){
	puts("task2 is called!");
}
void task3(void){
	puts("task3 is called!");
}
void task4(void){
	puts("task4 is called!");
}
void task5(void){
	puts("task5 is called!");
}
void task6(void){
	puts("task6 is called!");
}
void task7(void){
	puts("task7 is called!");
}
void scheduer(void);
void execute(void (*a[])(void),int n);
int main(void){
	scheduer();
	return 0;
}
void scheduer(void){
	void (*a[SIZE])(void);//一个函数指针数组
	int n=0;
	for(char c;(c=getchar())!=EOF;n++){
		switch(c){
			case '0':{
				a[n]=task0;
				break;
			}
			case '1':{
				a[n]=task1;
				break;
			}
			case '2':{
				a[n]=task2;
				break;
			}
			case '3':{
				a[n]=task3;
				break;
			}
			case '4':{
				a[n]=task4;
				break;
			}
			case '5':{
				a[n]=task5;
				break;
			}
			case '6':{
				a[n]=task6;
				break;
			}
			case '7':{
				a[n]=task7;
				break;
			}
		}
	}
	execute(a,n);
}

void execute(void (*a[])(void),int n){
	for(int i=0;i<n;i++){
		(a[i])();
	}
}
