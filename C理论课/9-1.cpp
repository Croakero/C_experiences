#include<stdio.h>
#if(0)
˼·�ǣ��ȴ洢һ�����ڵ���ȫƽ������
Ȼ��ԱȲ���¼N����֮ǰ�������ж��٣�Ȼ��b������c���� 
#endif 
int main(void){
	int all[100];
	for(int i=1;i<=100;i++){
		all[i-1]=i*i;
	}
	int n,num;
	scanf("%d",&n);
	for(num=0;all[num]<n;num++);//��all[num-1]λ���ϴ���˲�����n�������ȫƽ���� 
	for(int a=0;a<num;a++){//a��1������num-1 
	for(int b=0;b*b<=all[num-1]/10;b++){//b������all[num-1]/10
		for(int c=0;c<=num;c++){//c������num 
			if(all[a]==10*all[b]+all[c])
				printf("%d ",all[a]);
		}
	} 
}
	
}
