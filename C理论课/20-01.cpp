#include<stdio.h>
//�ҹ۲쵽�ݹ�һ�μ��ɽ������ 
int times=0;//����Ĵ���
int max;
int n=0;
int getnum(int row,int col,int (*p)[4]);
int main(){
int row,col=4;//����������
int n;//��ѭ���ⲿ����n��Ŀ������ѭ������ס���Լ���ȡ����λ���Ա���䣬���ҿ��Ʊ߽�ֵ 
scanf("%d", &row);
int i,j;
int p[row][4];
for(i=0; i<row; i++){
  for(j=0; j<col; j++){
    scanf("%d", &p[i][j]);//�����ά���������Ԫ��
  }
}	
	n=0;
	max=col*row;
	getnum(row,col,p);
    return 0;
}

int getnum(int row,int col,int p[][4]){
	int i=0,j=0;
	for(j=n; j<col-n; j++){//������ε��������
      printf("%d ",p[n][j]);
      times++;
    }
    if(max==times)return 0;
    for(i=n+1; i<row-n; i++){//������ε��ұߵ���
      printf("%d ",p[i][col-n-1]);
      times++;
    }
    if(max==times)return 0;
    for(j=col-n-2; j>=n; j--){
     printf("%d ",p[row-n-1][j]);//������ε��������
     times++;
    }
    if(max==times)return 0;
    for(i=row-n-2; i>n; i--){//������ε���ߵ���
     printf("%d ",p[i][n]);
     times++;
    }
    if(max==times)return 0; 
    n++;
    getnum(row,col,p);
}

