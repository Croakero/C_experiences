/*
思路 
比较n1-m1和n2-m2哪个大，先走完小的过程，接着就是
数组元素整体左移或者右移的问题了
这个还真不行这个，边界有值就不能推了 
行，说行就行，跑对了 
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
		int m01=m1,m02=m2;//记录读数 
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
		现在交换了两段，还有遗留的lucky个，需要循环右移。 
		右移lucky次,每次经过
		我要让处于m1+n2-m2+1的数据和处于n2的数据都被波及到,
		循环从m1+n2-m2+1开始到n2结束 
		*/
		for(int j=0;j<lucky;j++){//这层循环遍历所有没弄的项 
			temp=a[m1+n2-m2+1]; //从n2所在位置到n1都要移动，要右移 
			for(int i=m1+n2-m2+1;i<n2;i++){
				a[i]=a[i+1];
			}
			a[n2]=temp;//真狗啊这个判断 
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
		int m01=m1,m02=m2;//记录读数 
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
		现在交换了两段，还有遗留的lucky个，需要循环右移。 
		右移lucky次,
		从n1+1到n2都要波及到 
		*/
		for(int j=0;j<lucky;j++){//这层循环遍历所有没弄的项 
			temp=a[n2]; //从n2所在位置到n1+1都要移动，要右移 
			for(int i=n2;i>n1+1;i--){
				a[i]=a[i-1];
			}
			a[n1+1]=temp;//真狗啊这个判断 
		}
	}
}
