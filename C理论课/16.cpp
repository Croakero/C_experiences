#include<stdio.h>
int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	int u[n];
	int u1[k],u2[n-k];
	int num1=0;
	for(int num=0;num<n;num++){
		scanf("%d",&u[num]);
		//��û����printf("\n\n%d\n\n",u[num]);
	}
	for(int a=0;a<k;a++){
		u1[a]=u[a];
		//���ⲻ����printf("\n\n%d\n\n",u1[a]);
	}
	for(int b=k;b<n;b++){
		u2[num1]=u[b];
		num1++;
		//����Ҳ������printf("\n\n%d\n\n",u2[b]);
	}
	num1=0;
	//�Ҷ��ˣ��Ҷ����������ˣ��Ұ����ĵ�������Ū���� 
	for(int c=0;c<n-k;c++){
		u[c]=u2[c];
		//��������printf("\n\n%d\n\n",u[c]);
	}
	for(int d=n-k;d<n;d++){
		u[d]=u1[num1];
		num1++;
	}
	
	for(int i=0;i<n;i++)
		printf("%d ",u[i]);
		
	return 0;
}
