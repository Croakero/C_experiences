/*
�۲쵽��ɨ����Կ����ĸ�����һ�鲻��ѭ���Ĺ��̣�����������=���������� 
���ڴˣ���һ��������ÿ��ɨ��ı߽�ֵ�����ϴε�+1��-1 
���ҵ�˼·��������û����ʲô�����ʵĵط� 
*/
#include<stdio.h>
int main(){
int row,col=4;//����������
int n;//��ѭ���ⲿ����n��Ŀ������ѭ������ס���Լ���ȡ����λ���Ա���䣬���ҿ��Ʊ߽�ֵ 
int times=0;//����Ĵ���
scanf("%d", &row);
int i,j;
int p[row][4];
for(i=0; i<row; i++){
  for(j=0; j<col; j++){
    scanf("%d", &p[i][j]);//�����ά���������Ԫ��
  }
}
int max=col*row; 
for(n=0; ; n++){
    for(j=n; j<col-n; j++){//������ε��������
      printf("%d ",p[n][j]);
      times++;
    }
    if(max==times)break;
    for(i=n+1; i<row-n; i++){//������ε��ұߵ���
      printf("%d ",p[i][col-n-1]);
      times++;
    }
    if(max==times)break;
    for(j=col-n-2; j>=n; j--){
     printf("%d ",p[row-n-1][j]);//������ε��������
     times++;
    }
    if(max==times)break;
    for(i=row-n-2; i>n; i--){//������ε���ߵ���
     printf("%d ",p[i][n]);
     times++;
    }
    if(max==times)break;
}
    return 0;
}

