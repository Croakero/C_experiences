#include<stdio.h>
int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	int u[n];
	int u1[k],u2[n-k];
	int num1=0;
	for(int num=0;num<n;num++){
		scanf("%d",&u[num]);
		//这没问题printf("\n\n%d\n\n",u[num]);
	}
	for(int a=0;a<k;a++){
		u1[a]=u[a];
		//问题不在这printf("\n\n%d\n\n",u1[a]);
	}
	for(int b=k;b<n;b++){
		u2[num1]=u[b];
		num1++;
		//问题也不在这printf("\n\n%d\n\n",u2[b]);
	}
	num1=0;
	//我懂了，我懂问题在哪了，我把下文的数据数弄错了 
	for(int c=0;c<n-k;c++){
		u[c]=u2[c];
		//问题在这printf("\n\n%d\n\n",u[c]);
	}
	for(int d=n-k;d<n;d++){
		u[d]=u1[num1];
		num1++;
	}
	
	for(int i=0;i<n;i++)
		printf("%d ",u[i]);
		
	return 0;
}
