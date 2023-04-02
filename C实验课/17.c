/*
思路：
1 1 1 1 1 1
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4 
在主调函数中设计一个二维数组，m行n列
然后把这个数组和m、n传入change()函数
change里面定义一个n行m列的数组，把j,k赋值k,j
然后再遍历列翻转 
最后打印
事情会像我想的那么简单吗
*/ 

#include<stdio.h>
int m,n;
void change(int m,int n,int (*a)[n]);
int main(void){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	change(m,n,a);
	return 0;
}
void change(int m,int n,int a[m][n]){
	int b[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i][j]=a[j][i];
		}
	}
	int temp;
	for(int i=0;i<n/2;i++){
		for(int j=0;j<m;j++){
			temp=b[i][j];
			b[i][j]=b[n-i-1][j];
			b[n-i-1][j]=temp;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j!=m-1)printf("%d ",b[i][j]);
			else printf("%d",b[i][j]);
		}
		putchar('\n');
	}
}
