#include<stdio.h>
//我观察到递归一次即可解决问题 
int times=0;//输出的次数
int max;
int n=0;
int getnum(int row,int col,int (*p)[4]);
int main(){
int row,col=4;//行数和列数
int n;//在循环外部构造n的目的是让循环“记住”自己读取到的位置以便拐弯，并且控制边界值 
scanf("%d", &row);
int i,j;
int p[row][4];
for(i=0; i<row; i++){
  for(j=0; j<col; j++){
    scanf("%d", &p[i][j]);//输入二维数组的所有元素
  }
}	
	n=0;
	max=col*row;
	getnum(row,col,p);
    return 0;
}

int getnum(int row,int col,int p[][4]){
	int i=0,j=0;
	for(j=n; j<col-n; j++){//输出回形的上面的行
      printf("%d ",p[n][j]);
      times++;
    }
    if(max==times)return 0;
    for(i=n+1; i<row-n; i++){//输出回形的右边的列
      printf("%d ",p[i][col-n-1]);
      times++;
    }
    if(max==times)return 0;
    for(j=col-n-2; j>=n; j--){
     printf("%d ",p[row-n-1][j]);//输出回形的下面的行
     times++;
    }
    if(max==times)return 0;
    for(i=row-n-2; i>n; i--){//输出回形的左边的列
     printf("%d ",p[i][n]);
     times++;
    }
    if(max==times)return 0; 
    n++;
    getnum(row,col,p);
}

