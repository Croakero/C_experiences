/*
思路，开一个二维数组，二十排，每排五个座位
我还是开一个一维结构数组，100个元素，结构内含是否卖出和座位两个元素 
需要先来一个循坏给结构赋值 
******************** 
一个函数接受购买次数n，在内层的内层循环判断，发现为n刚好需要判断5-n次，从1开始
内层i,j，i从1到20，等于二十，j从1到5，等于五，数组i*j-1元素
在j循环中实现判断座位，在进入j之前赋值count=0;每发现一个可以操作的（非0）就count++，当count==buy的时候退出循环
然后输出，再记录total,再开一个循环，把i*j-1到i*j-1+count的isblank全部化为0
total==TOTAL的话，即如果发现没有连座且此时已经到达座位末尾，则重开一个循环,
********************
这个循环来买不连号的 
*/
#include<stdio.h>
#define ROW 20
#define EACH 5
#define TOTAL 100
struct seats{
	int first;
	char No[2];
	int isblank;
};
void select(struct seats *);

int main(void){
	struct seats ar[TOTAL];
	struct seats* ptr=ar;
	int i,j;
	int mule=1;//mule仅用在接下来的循环中表示循环次数 
	for(i=0;i<ROW;i++){
		for(j=0;j<EACH;j++){						//这有问题，它不到20 
			ptr->first=mule;
			if(j!=4) 
			ptr->No[0]='A'+j;
			else
			ptr->No[0]='F';//为啥铁路不弄个E呢 
			ptr->No[1]='\0';
			ptr->isblank=1;
			ptr++;
		}
			mule++;
	}
	ptr=ar;//重置指针 
	select(ptr);
	
	return 0;
}

void select(struct seats * ptr){
	int num;//控制能买多少次票 
	scanf("%d",&num);
	int count;//控制能否买到票 
	for(int k=0;k<num;k++){//这层控制循环读取 
		int buy;
		int total=0;//买这次的一些票尝试了了多少次 
		scanf("%d",&buy);//控制买几张票 
		int i,j;//控制座位坐标 
		for(i=1;i<=ROW;i++){//遍历所有排 
			count=0;//count控制看能买多少张票 
			for(j=1;j<=EACH;j++){//遍历每排所有座位 
				if((ptr+total)->isblank==1){
					count++;
				}
				else{
					count=0;
				}
				total++;
				if(count==buy){
					break;
				}
			}
			if(count==buy){
				break;
			}
		}
		int m=0;//m是已经买的票数 
		if(total!=TOTAL){
			for(int l=total-count;m<buy;m++){//输出部分 
				printf("%d%s",(ptr+l+m)->first,(ptr+l+m)->No);//输出名字 
				(ptr+l+m)->isblank=0;//将位置重置为买过了
				if(m!=buy-1){
					putchar(' ');
				}
				else{
					putchar('\n');
				}
			}
		}
		else{//如果已经尝试了一百次还没有找到连号 
			int done=0;//已经买的票数 
			for(int i=0;i<TOTAL&&done!=buy;i++){
				if((ptr+i)->isblank==1){
					(ptr+i)->isblank=0;
					printf("%d%s",(ptr+i)->first,(ptr+i)->No);
					done++;
					if(done==buy){
						putchar('\n');
					}
					else{
						putchar(' ');
					}
				}
			}
		}
	}
}
