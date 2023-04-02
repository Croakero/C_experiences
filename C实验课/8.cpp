/*思路：
外层n遍历1~10000，这个循环放在main()里面 
内层从1遍历，直到n/2找到n的所有因数，设计一个变量计算总和， 
并且把所有因数存放在数组里，开一个大一点的静态数组，
数组元素全部赋值为0.
找到所有因数后判断总和是否为n，然后总和清0，
如果是的话就返回1，main()看见它返回的1就输出之
再在main()里面开一个循环走静态数组内容直到非0； 
开始！ 
*/

#include<stdio.h>
#define SIZE 10000
int isperfect(int);
int small[100]={0};
int num=0;

int main(void){
	int i;
	for(i=1;i<SIZE;i++){
		if(isperfect(i)){
			printf("%d=1",i);
			for(int m=1;m<num;m++){
				printf("+%d",small[m]);
			}
			putchar('\n');
		}
	}
	return 0;
}
int isperfect(int n){
	int m,sum=0;
	num=0;
	for(m=1;m<=n/2;m++){
		if(n%m);
		else {
			small[num]=m;
			num++;
			sum+=m;
		}
	}
	if(sum==n)
	return 1;
	else return 0;
}
