/*
˼·��
1 1 1 1 1 1
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4 
���������������һ����ά���飬m��n��
Ȼ�����������m��n����change()����
change���涨��һ��n��m�е����飬��j,k��ֵk,j
Ȼ���ٱ����з�ת 
����ӡ
��������������ô����
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
