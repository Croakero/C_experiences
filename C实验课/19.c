/*
˼·��
�˸�������main�������scheduler������scheduerѭ����ȡ 
�ַ�������֮ǰ����һ������ָ�����飬
Ԫ��ָ�򷵻�ֵ���βζ���void�ĺ��� 
Ȼ��ÿ��ѭ��ǰreallocһ�£�(Ϊɶ��realloc������)�ÿ������� 
����������Ͱ�˳��洢������ȵĺ���
Ȼ���������������������ݸ�execute������execute������
��һ��ѭ����Ȼ�����ÿһ��Ԫ�ض�Ӧ�ĺ����� 
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
	void (*a[SIZE])(void);//һ������ָ������
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
