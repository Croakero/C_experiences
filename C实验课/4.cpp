/*ѭ����ȡ���룬������벻�Ǹ�̾�ţ���ô�ж��Ƿ�Ϊ�ո������¼Ϊ1
�ٶ�ȡ��һ���ǲ��ǿո�������ǿո���ô���ch��temp���ٽ��Ŷ�ȡ
����ǿո���ô��������ֱ�������ǿո�Ϊֹ 
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
