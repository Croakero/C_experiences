/*
˼· 
�Ƚ�n1-m1��n2-m2�ĸ���������С�Ĺ��̣����ž���
����Ԫ���������ƻ������Ƶ�������
������治��������߽���ֵ�Ͳ������� 
�У�˵�о��У��ܶ��� 
*/

#include<stdio.h>
void change(int *,int,int,int,int,int);
int main(void){
	int n;
	int m1,n1,m2,n2;
	fscanf(stdin,"%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&a[i]);
	}
	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);
	change(a,m1,n1,m2,n2,n);
	for(int i=0;i<n;i++){
		fprintf(stdout,"%d ",a[i]);
	}
	return 0;
}

void change(int *a,int m1,int n1,int m2,int n2,int n){
	if(n1-m1>n2-m2){
		int lucky=n1-m1-n2+m2;
		int m01=m1,m02=m2;//��¼���� 
		for(int temp;m2<=n2;m2++){
			temp=a[m1];
			a[m1]=a[m2];
			a[m2]=temp;
			m1++;
		}
		m1=m01;
		m2=m02;
		int temp;
		/*
		���ڽ��������Σ�����������lucky������Ҫѭ�����ơ� 
		����lucky��,ÿ�ξ���
		��Ҫ�ô���m1+n2-m2+1�����ݺʹ���n2�����ݶ���������,
		ѭ����m1+n2-m2+1��ʼ��n2���� 
		*/
		for(int j=0;j<lucky;j++){//���ѭ����������ûŪ���� 
			temp=a[m1+n2-m2+1]; //��n2����λ�õ�n1��Ҫ�ƶ���Ҫ���� 
			for(int i=m1+n2-m2+1;i<n2;i++){
				a[i]=a[i+1];
			}
			a[n2]=temp;//�湷������ж� 
		}
	}
	else if(n1-m1==n2-m2){
		for(int temp;m2<=n2;m2++){
			temp=a[m1];
			a[m1]=a[m2];
			a[m2]=temp;
			m1++;
		}
	}
	else if(n1-m1<n2-m2){
		int lucky=n1-m1-n2+m2;
		lucky=-lucky;
		int m01=m1,m02=m2;//��¼���� 
		for(int temp;m1<=n1;m2++){
			temp=a[m1];
			a[m1]=a[m2];
			a[m2]=temp;
			m1++;
		}
		m1=m01;
		m2=m02;
		int temp;
		/*
		���ڽ��������Σ�����������lucky������Ҫѭ�����ơ� 
		����lucky��,
		��n1+1��n2��Ҫ������ 
		*/
		for(int j=0;j<lucky;j++){//���ѭ����������ûŪ���� 
			temp=a[n2]; //��n2����λ�õ�n1+1��Ҫ�ƶ���Ҫ���� 
			for(int i=n2;i>n1+1;i--){
				a[i]=a[i-1];
			}
			a[n1+1]=temp;//�湷������ж� 
		}
	}
}
