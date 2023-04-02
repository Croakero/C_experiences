/*
观察到每一行都要有一个皇后，思路是网上学的回溯递归法
按顺序依次尝试放置皇后，遍历每一行和每一列，行是大循环，列在小循环 
*/ 
#include<stdio.h>
int queen[10]={0};// 以行为下标的数组记录列数 
int count =0;
int check(int,int);
int tryer(int,int); 
int main(void){
	int numofqueens;
	scanf("%d",&numofqueens);
	tryer(0,numofqueens);
	if(count!=0)
	printf("%d",count);
	else printf("无解"); 
	return 0;
}

int check(int row,int col){//这个函数得到一个行数和列数，判断该位置是否能放皇后 
	for(int i=0;i<row;i++){//遍历所有行 
		if(col==queen[i])//同一列 
		return 0;
		if(i+queen[i]==col+row)//对角线，行加列等于行加列 
		return 0;
		if(i-queen[i]==row-col)//对角线，这次是减法
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
				queen[row]=0;//如果到达了末尾，那么把刚放的这个清零 
				return 0;
			}
		tryer(row+1,num);
		queen[row]=0;
		} 
	}
}
