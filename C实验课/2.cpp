#include<stdio.h>
int main(void){
	unsigned short x,m,n;
	fscanf(stdin,"%hx%hu%hu",&x,&m,&n);
	unsigned mask=(0xffff>>m)<<(16-n);//��mλ���1λ�ǲ��ǵ�mλ
	//printf("%x %d %d ",x,m,n);
	if(m>=0&&m<=15&&n>=1&&n<=(16-m)){
		x=(x>>m)<<(16-n); 
		x=x&mask;
		printf("%hx",x); 
	}
	else printf("error");
	return 0;
}
//��0 �ܣ��15, 1 �ܣ��16-��
