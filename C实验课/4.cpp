/*循环读取输入，如果输入不是感叹号，那么判断是否为空格，是则记录为1
再读取下一个是不是空格，如果不是空格，那么输出ch和temp，再接着读取
如果是空格，那么丢弃输入直到读到非空格为止 
*/


#include<stdio.h>
int main(void){
	char ar[250]={'\0'};
	int i=0;
	char ch,temp;
	while((ch=getchar())!='!'){
		if(ch==' '){
			while((temp=getchar())==' ');
			ar[i]=ch;
			i++;
			ar[i]=temp;
			i++;
			if(temp=='!'){
				printf("%s",ar);
				return 0;
			}
		}
		else {
			ar[i]=ch;
			i++;
		}
	}
	ar[i]=ch;
	printf("%s",ar);
	return 0;
} 
