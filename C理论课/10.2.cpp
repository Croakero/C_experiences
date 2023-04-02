#include<stdio.h>
int main(void){
	long long int n,x;
	const long long int N=998244353;
	scanf("%lld",&n);
	for(x=0;x<=N-1;x++)
	{
		if(!((n-x)%N)){
			printf("%lld",x);
			break;
		}
	}
	return 0;
} 
