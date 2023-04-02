/*
思路：
首先设置一个n*80的二维数组，扫入那些字符
然后把这个数组传入delete函数，还有n 
delete函数
**********
这个方法太俗套了
首先在main函数里面扫入n，开一个for循环
整一个n元素字符型指针数组，对于第[i]个指针元素，
给这个指针malloc一个字节的单位,这个读取要再开一个循环
用来getchar()读入数据，直到读到'\0'内层循环结束 
扫描结束后开一个for循环，或者直接在for循环内部实现
循环调用删除函数，传给函数的是指针数组的第i个成员
然后来处理函数内部的细节
delete函数需要是一个返回字符指针返回值类型的函数 
先存起始位置，然后让指针自增，
如果isblank()函数返回真，就把起始位置设置为指针处，
直到读到非空格和水平制表符为止
然后整两个指针，一个prev一个current(current是已经递增的指针)，还要记录剩下的数据长度 
如果prev和current的内容都指向了空格，那么把这个空格变为'\0'再数组循环移动
yikesou 
**********
啊啊啊啊我为什么不用链表，这样就可以
咦？ 我为什么不可以像处理链表那样处理
噢不行，数组不能越过某个地方指向其他地方，我还是重构吧，用链表 
来延续刚才的思路
噢不对不对，指向字符的数组不是指向结构的数组，得回到数组
********** 
*/

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *delete(char * ptr);
int main(void){
	int n,j;
	scanf("%d",&n);
	while(getchar()!='\n');
	char *a[n];
	char c;
	for(int i=0;i<n;i++){
		a[i]=(char *)malloc(sizeof(char));//先申请一块内存 
		for(j=0;(c=getchar())!='\n';j++){
			a[i]=realloc(a[i],j+1);
			a[i][j]=c;
		}
		a[i]=realloc(a[i],j+1);//原来的只到j+1，我不放换行符，这脑瘫题。放一个'\0' 
		a[i][j]='\0';
	}
	//这波真是起飞了这个，无冗余读取居然奏效了
	/*
	a debug boi
	for(int i=0;i<n;i++){
		puts(a[i]);
	}
	*/
	//噢我想到了下面读取字符串长度的方法，strlen函数！ 
	for(int i=0;i<n;i++){
		a[i]=delete(a[i]);
		printf("%s",a[i]);
		if(i!=n-1){
			putchar('\n');
		}
	}
	return 0;
}

char *delete(char * ptr){
	char *head=ptr;
	char *prev=NULL;
	for(int isstart=0;*ptr!='\0';ptr++){//isstart用来判断是否已经开始字符串 
		if(isstart==0&&isblank(*ptr)){
			head++;
		}
		else if(isstart==0){
			isstart=1;
		}
		if(isstart==1){
			if(prev==NULL){
				prev=ptr-1;//这里可能越界，但不会有问题，现在的prev和ptr不可能均是指向空格 ，因为行首已经没有空格了 
			}
			if(*prev==' '&&*ptr==' '){
				while(*ptr==' '){
					int num=strlen(ptr)+1;//测量这之后的长度
					char* current=ptr;//设置一个指针指向现在位置 
					for(int i=0;i<num;i++){
						*current=*(current+1);
						current++;
					}
					*(current-1)='\0';
				}//转了好多次，但是此时prev没有变，ptr指向的是下一个字符 
			}
		}
		if(prev!=NULL) prev++;
	}
	return head;
}
