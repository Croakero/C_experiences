/*
˼·��
������Ǻܺ��룬main���𷴸����룬==0��ֹͣ����λ������n
��ֱ�ӿ��˸���̬��������nʹ�� ��ÿ���жϽ�����˸���̬����ȫ����0
��̫�����ˣ�
������ÿ�μ�������һ�����Һܴ�ģ�����Ż�����
���У���������⣬�ҵû����뷨 
��Ŀ��������У����������ж��ǲ�������������������������
��һ���������жϵ���n���ڶ�����λ��k������λ�����ƣ� 
ֱ��k==1��sum+=n%pow(10,k-1)��n/10��k-- 
�����￪һ��sum�����������ܺ��Ƿ�Ϊn
����ǣ�����1�����Ƿ���0

main()������ѭ������k��������0�Ļ���
forѭ���жϴ�pow(10,k)��pow(10,k-1)
����������������������������̬���飬��������һ��������ӡ
������ô��ôϲ���þ�̬��������ΪĿǰ��������ָ�뷽��
*/

#include<stdio.h>
#include<math.h>
int check(int ,int );
void print(int ,int ); 
unsigned int ar[100]={0};
int main(void){
	unsigned int k;
	int count;
	while(scanf("%d",&k)){//��������ǵ�һ�γ��� 
		if(k==0)
			return 0;
		for(int mule=pow(10,k-1);mule<=pow(10,k);mule++){
			if(check(mule,k)){
				ar[count]=mule;
				count++;	
			}
		}
		print(k,count);
		count=0;
	}
	return 0;
}

int check(int n,int k){
	int sum=0,temp;
	int fakek,faken=n;//faken��������ѭ�� 
	for(fakek=0;fakek<k;fakek++){
		temp=faken%10;
		sum+=pow(temp,k);
		faken=faken/10;
	}
	if(sum==n)
	return 1;
	return 0;
}

void print(int k,int count){
	switch(k){
		case 3:
			printf("%uλ��ˮ�ɻ�������%d��",k,count);
			break;
		case 4:
			printf("%uλ����Ҷõ��������%d��",k,count);
			break;
		case 5:
			printf("%uλ�������������%d��",k,count);
			break;
		case 6:
			printf("%uλ������������%d��",k,count);
			break;
		case 7:
			printf("%uλ�ı�����������%d��",k,count);
			break;
		case 8:
			printf("%uλ�İ���������%d��",k,count);
			break;
	}
	for(int mule=0;mule<count;mule++){
		if(mule!=count-1)
			printf("%d,",ar[mule]);
		else
			printf("%d\n",ar[mule]);
			ar[mule]=0;
	} 
}
