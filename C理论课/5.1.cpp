#include<stdio.h>
int main(void){
	int ar1[7]={1,3,5,7,8,10,12};
	int ar2[4]={4,6,9,11};
	int y,m,d;
	int i,j,tot=0;
	scanf("%d %d %d",&y,&m,&d);
	for(i=0;m>ar1[i];i++);
	for(j=0;m>ar2[j];j++);
	if(m>2){
		if(y%4)
			tot+=28;
		else if((y%100)&&(y%400){
			
		}
			tot+=29;
	}
	tot+=i*31;
	tot+=j*30;
	tot+=d;
	printf("%d",tot);
} 
