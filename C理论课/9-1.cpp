#include<stdio.h>
#if(0)
思路是，先存储一万以内的完全平方数，
然后对比并记录N及其之前的数字有多少，然后b遍历，c遍历 
#endif 
int main(void){
	int all[100];
	for(int i=1;i<=100;i++){
		all[i-1]=i*i;
	}
	int n,num;
	scanf("%d",&n);
	for(num=0;all[num]<n;num++);//在all[num-1]位置上存放了不超过n的最大完全平方数 
	for(int a=0;a<num;a++){//a从1遍历到num-1 
	for(int b=0;b*b<=all[num-1]/10;b++){//b遍历到all[num-1]/10
		for(int c=0;c<=num;c++){//c遍历到num 
			if(all[a]==10*all[b]+all[c])
				printf("%d ",all[a]);
		}
	} 
}
	
}
