/*
观察到，扫描可以看作四个动作一组不断循环的过程，即上右下左=》上右下左 
基于此，另一个发现是每次扫描的边界值都是上次的+1与-1 
就我的思路来看，我没发现什么不合适的地方 
*/
#include<stdio.h>
int main(){
int row,col=4;//行数和列数
int n;//在循环外部构造n的目的是让循环“记住”自己读取到的位置以便拐弯，并且控制边界值 
int times=0;//输出的次数
scanf("%d", &row);
int i,j;
int p[row][4];
for(i=0; i<row; i++){
  for(j=0; j<col; j++){
    scanf("%d", &p[i][j]);//输入二维数组的所有元素
  }
}
int max=col*row; 
for(n=0; ; n++){
    for(j=n; j<col-n; j++){//输出回形的上面的行
      printf("%d ",p[n][j]);
      times++;
    }
    if(max==times)break;
    for(i=n+1; i<row-n; i++){//输出回形的右边的列
      printf("%d ",p[i][col-n-1]);
      times++;
    }
    if(max==times)break;
    for(j=col-n-2; j>=n; j--){
     printf("%d ",p[row-n-1][j]);//输出回形的下面的行
     times++;
    }
    if(max==times)break;
    for(i=row-n-2; i>n; i--){//输出回形的左边的列
     printf("%d ",p[i][n]);
     times++;
    }
    if(max==times)break;
}
    return 0;
}

