/*˼·��
���n����1~10000�����ѭ������main()���� 
�ڲ��1������ֱ��n/2�ҵ�n���������������һ�����������ܺͣ� 
���Ұ���������������������һ����һ��ľ�̬���飬
����Ԫ��ȫ����ֵΪ0.
�ҵ������������ж��ܺ��Ƿ�Ϊn��Ȼ���ܺ���0��
����ǵĻ��ͷ���1��main()���������ص�1�����֮
����main()���濪һ��ѭ���߾�̬��������ֱ����0�� 
��ʼ�� 
*/

#include<stdio.h>
#define SIZE 10000
int isperfect(int);
int small[100]={0};
int num=0;

int main(void){
	int i;
	for(i=1;i<SIZE;i++){
		if(isperfect(i)){
			printf("%d=1",i);
			for(int m=1;m<num;m++){
				printf("+%d",small[m]);
			}
			putchar('\n');
		}
	}
	return 0;
}
int isperfect(int n){
	int m,sum=0;
	num=0;
	for(m=1;m<=n/2;m++){
		if(n%m);
		else {
			small[num]=m;
			num++;
			sum+=m;
		}
	}
	if(sum==n)
	return 1;
	else return 0;
}
