 #include<stdio.h>
void change(int *a,int,int);
int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	int u[n];
	for(int num=0;num<n;num++){
		scanf("%d",&u[num]);
		//��û����printf("\n\n%d\n\n",u[num]);
	}
	change(u,n,k);
	for(int i=0;i<n;i++)
		printf("%d ",u[i]);
		
	return 0;
}

void change(int *a,int n,int k){
	for(int i=0;i<k;i++){//һ������k�� 
		int temp=a[0];
		for(int s=0;s<n;s++){
			a[s]=a[s+1];
		}
		a[n-1]=temp;
	}
}
