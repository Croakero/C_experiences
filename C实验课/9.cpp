/*
思路：
这个不是很好想，main负责反复输入，==0则停止，把位数传给n
我直接开八个静态变量，供n使用 ，每次判断结束后八个静态变量全整成0
（太暴力了）
那岂不是每次计算量是一样而且很大的？这个优化很烂
不行，这个有问题，我得换个想法 
题目给了我灵感，函数用来判断是不是自幂数，传入两个参数，
第一个是用来判断的数n，第二个是位数k，利用位数控制： 
直到k==1，sum+=n%pow(10,k-1)，n/10，k-- 
函数里开一个sum变量，计算总和是否为n
如果是，返回1，不是返回0

main()函数里循环输入k，不等于0的话，
for循环判断从pow(10,k)到pow(10,k-1)
如果是自幂数，存在数组里，开个静态数组，再设置另一个函数打印
（我怎么这么喜欢用静态变量）因为目前来看它比指针方便
*/

#include<stdio.h>
#include<math.h>
int check(int ,int );
void print(int ,int ); 
unsigned int ar[100]={0};
int main(void){
	unsigned int k;
	int count;
	while(scanf("%d",&k)){//这个控制是第一次尝试 
		if(k==0)
			return 0;
		for(int mule=pow(10,k-1);mule<=pow(10,k);mule++){
			if(check(mule,k)){
				ar[count]=mule;
				count++;	
			}
		}
		print(k,count);
		count=0;
	}
	return 0;
}

int check(int n,int k){
	int sum=0,temp;
	int fakek,faken=n;//faken用来控制循环 
	for(fakek=0;fakek<k;fakek++){
		temp=faken%10;
		sum+=pow(temp,k);
		faken=faken/10;
	}
	if(sum==n)
	return 1;
	return 0;
}

void print(int k,int count){
	switch(k){
		case 3:
			printf("%u位的水仙花数共有%d个",k,count);
			break;
		case 4:
			printf("%u位的四叶玫瑰数共有%d个",k,count);
			break;
		case 5:
			printf("%u位的五角星数共有%d个",k,count);
			break;
		case 6:
			printf("%u位的六合数共有%d个",k,count);
			break;
		case 7:
			printf("%u位的北斗星数共有%d个",k,count);
			break;
		case 8:
			printf("%u位的八仙数共有%d个",k,count);
			break;
	}
	for(int mule=0;mule<count;mule++){
		if(mule!=count-1)
			printf("%d,",ar[mule]);
		else
			printf("%d\n",ar[mule]);
			ar[mule]=0;
	} 
}
