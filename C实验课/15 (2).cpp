/*
思路：
直接位移，先把m1~n1右移，移动到右对齐原n2，
此时的n2在m1左边一格， 
把现在的m2~n2左移到和原来的m1左对齐，
 
*/
#include<stdio.h>
void change(int);

int main(void){
	int n;
	scanf("%d",&n);
	void change(n);
	return 0; 
}

void change(int n){
	int a[n];
	int m1,m2,n1,n2,temp;
	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n1-m1;i++){
		temp=a[n1]
		for(int j=0;j)
	}
}
