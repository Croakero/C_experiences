/*
�۲쵽ÿһ�ж�Ҫ��һ���ʺ�˼·������ѧ�Ļ��ݵݹ鷨
��˳�����γ��Է��ûʺ󣬱���ÿһ�к�ÿһ�У����Ǵ�ѭ��������Сѭ�� 
*/ 
#include<stdio.h>
int queen[10]={0};// ����Ϊ�±�������¼���� 
int count =0;
int check(int,int);
int tryer(int,int); 
int main(void){
	int numofqueens;
	scanf("%d",&numofqueens);
	tryer(0,numofqueens);
	if(count!=0)
	printf("%d",count);
	else printf("�޽�"); 
	return 0;
}

int check(int row,int col){//��������õ�һ���������������жϸ�λ���Ƿ��ܷŻʺ� 
	for(int i=0;i<row;i++){//���������� 
		if(col==queen[i])//ͬһ�� 
		return 0;
		if(i+queen[i]==col+row)//�Խ��ߣ��м��е����м��� 
		return 0;
		if(i-queen[i]==row-col)//�Խ��ߣ�����Ǽ���
		return 0; 
	}
	return 1;
}

int  tryer(int row,int num){
	for(int col=0;col<num;col++){
		if(check(row,col)){
			queen[row]=col;
			if(row==num-1){
				count++;
				queen[row]=0;//���������ĩβ����ô�Ѹշŵ�������� 
				return 0;
			}
		tryer(row+1,num);
		queen[row]=0;
		} 
	}
}
