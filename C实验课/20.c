/*
思路：
这个题有点意思啊有点意思
先把矩阵读到m行n列二维数组里，a[m][n]。
我的建议是做一个指向其列数这一一维数组的指针ptr 
这样我就可以用这个指针横向和纵向移动了。 
它现在指向第一行第一列，取它的ptr[0]，
然后ptr++，取0，ptr--，取1，
这其中暗藏了一些我尚未发现的数学规律
我想想啊，如果行数，即ptr+1没怼到外面去，但是这怎么判断呢？
每次对ptr++的时候，一个计数器p跟着递增，初始值为0，
如果计数器是m-1，那么此时不再ptr++，变成q++,ptr[q+1]
然后ptr--，q++直到q怼到n-1上面去
********** 试错之后 
观察到Z扫描可以可以分为三个过程，一个是上三角扫描过程，
一个是连续续扫描相同大小的斜线i次，和有规律下三角扫描。
 把不同的做法定义为函数，然后操控指针移动，不需要指针有那么高的智能。
 采取的打印策略是移动后打印 
*/
#include<stdio.h>
//给这些函数传入两个值，后者是目前的位置，结束后要把返回值赋给当前位置
//有问题，指针不会变化,我要用宏 
#ifdef aDEBUG 
int upright(int (*ptr)[],int num);//右上方移动
int downleft(int (*ptr)[],int num);//左下方移动
int right(int (*ptr)[],int num);//向右一个单位 
int down(int (*ptr)[],int num);//向下一个单位 
#endif
#define UPRIGHT ptr--,oi++,printf("%d ",*((*ptr)+oi))
#define DOWNLEFT ptr++,oi--,printf("%d ",*((*ptr)+oi))
#define DOWN ptr++,printf("%d ",*((*ptr)+oi))
#define RIGHT oi++,printf("%d ",*((*ptr)+oi))

int main(void){
	int m,n;
	int oi=0;//用来判断目前的行数 
	scanf("%d%d",&m,&n);//m行n列
	int arr[m][n];//可理解为
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);//扫入二维数组 
		}
	}
	int (*ptr)[n]=&arr[0];//ptr是第一行第一列
	int j=1;//控制斜方向操作次数
	printf("%d ",(*ptr)[0]);
	if(m>=n){//当m>=n时
		int flag=1;/*先右 斜左下 再下 斜右上 右，单双用一个变量控制*/
		for(int i=0;i<n-1;i++,flag++){//循环m-1次，每次两个操作
			if(flag%2){//如果flag是单数
                RIGHT;
				for(int k=0;k<j;k++){//左下移动j次
				    DOWNLEFT;
				}
			}
			else{//如果flag是双数
                DOWN;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j++;//注意，j准备好了下一次变化，在退出大循环进入下一步的时候需要j--
        }
		j--;//让j匹配此时的斜线扫描次数
        for(int i=0;i<m-n;i++,flag++){//斜线不变扫描
            if(flag%2){//如果flag是单数
                DOWN;
                for (int k=0; k<j;k++) {
                    DOWNLEFT;
                }
            }
            else{
                DOWN;
                for (int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
        }
        j--;
        for(int i=0;i<n-1;i++,flag++){
            if(flag%2){//如果flag是单数
                DOWN;
                for(int k=0;k<j;k++){//左下移动j次
                    DOWNLEFT;
                }
            }
            else{//如果flag是双数
                RIGHT;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j--;
        }
	}
    else{
        int flag=1;/*先右 斜左下 再下 斜右上 右，单双用一个变量控制*/
        for(int i=0;i<m-1;i++,flag++){//循环m-1次，每次两个操作
            if(flag%2){//如果flag是单数
                RIGHT;
                for(int k=0;k<j;k++){//左下移动j次
                    DOWNLEFT;
                }
            }
            else{//如果flag是双数
                DOWN;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j++;//注意，j准备好了下一次变化，在退出大循环进入下一步的时候需要j--
        }
        j--;//让j匹配此时的斜线扫描次数
        for(int i=0;i<n-m;i++,flag++){//斜线不变扫描
            if(flag%2){//如果flag是单数
                RIGHT;
                for (int k=0; k<j;k++) {
                    DOWNLEFT;
                }
            }
            else{
                RIGHT;
                for (int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
        }
        j--;
        for(int i=0;i<m-1;i++,flag++){
            if(flag%2){//如果flag是单数
                DOWN;
                for(int k=0;k<j;k++){//左下移动j次
                    DOWNLEFT;
                }
            }
            else{//如果flag是双数
                RIGHT;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j--;
        }
    }
}



#ifdef aDEBUG
int upright(int (*ptr)[],int num){
	ptr++;
	num--;
	printf("%d",ptr[num]);
	return num;
}

int downleft(int(*ptr)[],int num){
	ptr--;
	num++;
	printf("%d",ptr[num]);
	return num;
}

int right(int (*ptr)[],int num){
	ptr++;
	printf("%d",ptr[num]); 
} 

int down(int (*ptr)[],int num){
	num++;
	printf("%d",ptr[num]);
}
#endif
