/*
这代码比狗屎还丑陋 
*/

#include<stdio.h>
struct dates{
	int ay;
	int onth;
	int ear;
};
int main(void){
	struct dates now;
	int ar1[7]={1,3,5,7,8,10,12};
	int ar2[4]={4,6,9,11};
	int i,j,tot=0;
	scanf("%d %d %d",&now.ear,&now.onth,&now.ay);
	if(now.onth>12||now.onth<1||now.ay<1||now.ay>31)
	{
		fprintf(stdout,"error");
		return 0;
	}
	for(i=0;now.onth>ar1[i];i++);
	for(j=0;now.onth>ar2[j]&&j<4;j++);
	int max=ar1[i]>ar2[j]?1:0;
	if(max==1){
		if(now.ay>31){
		printf("error");
		return 0;
	}
	}
	else{
		if(now.ay>32){
		printf("error");
		return 0;
	}
}
	if(now.onth==2){
		if(now.ear%4||((!(now.ear%100))&&(now.ear%400))){
			if(now.ay>28)
			printf("error");
			return 0;
		}
		else if(now.ay>29){
			printf("error");
			return 0;
		}

	}
	if(now.onth>2){
		if(!(now.ear%100)&&!(now.ear%400))//now.ear能被400和100整除 
			tot+=29;
		else if(now.ear%100&&!(now.ear%4))//不能被100整除但能被4整除
			tot+=29;
		else tot+=28; 
	}
	tot+=i*31;
	tot+=j*30;
	tot+=now.ay;
	printf("%d",tot);
}

