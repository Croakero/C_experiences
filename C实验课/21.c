/*
˼·��
���õ�ʮ�˹ص���������˼�룬������洢����ϲ������
��һ�����ַ���temp��SIZE����һ��
��һ��ָ�����飬malloc����ռ�һ��ָ���С
********�� 
scanf�ܶ���������ѭ����ȡ����һ��ѭ��
��ȡ�����ݴ浽temp���棬Ȼ������Ҫ����������
ָ���������һ����Ԫ�أ���Ҫһ�������� 
��Ԫ�ط����ڴ棬��temp��Ķ����浽�����棬
Ȼ�����temp 
��������ͻȻ�뵽�Ǹ����ص����⣬���ѭ�����������������������˼·
������������˼�ģ���ÿ��scanf֮��getcharһ��(δ���ô�˼·)
**********
������˼· 
��Ҫ����getchar()�Ļ� 
c���ǻ��е�ʱ�����c�ǿո�(ע�⴦��ͷԪ��) 
realloc��ָ�������һ��Ԫ�أ���Ҫһ��������(�ⲽ��ס��)
������Ҫ��˼·�����������ȡ���ٰ�����Ԫ�ظ����� 
�����������Ǹ�Ԫ��
��������Ǹ�Ԫ��ѭ����ȡ 
********
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
char * find(char *a[],int);
struct data{
	char *c;
	struct data *next;
}; 
int main(void){
	char temp[SIZE]; 
	int i=0,inword=0,count=0;
	struct data *head=(struct data *)malloc(sizeof(struct data)),*current=head;
	for(char c=getchar();c!='\n';c=getchar()){
		if(c!=' '){//���c���ǿո�
			temp[i]=c;
			i++;
		}
		else if(c==' '){//���c�ǿո� 
			current->c=(char *)malloc(i*sizeof(char)+1);
			strncpy(current->c,temp,i);
			current->c[i]='\0';//��һ���ַ������� 
			i=0;
			current->next=(struct data *)malloc(sizeof(struct data));//current����ǰ���ռ� 
			current=current->next; 
			count++;
		}
	}//ֵ��ע����Ǵ�ʱ���һ���ַ���û�����
	current->c=(char *)malloc(i*sizeof(char)+1);
	strncpy(current->c,temp,i);
	current->c[i]='\0';//��һ���ַ������� 
	i=0;
	current->next=NULL; 
	count++;
	char *a[count];
	current=head;
	for(int i=0;i<count;i++){
		a[i]=current->c;
		current=current->next;
		//puts(a[i]);Ŀǰһ������ 
	}
	char *the_one=find(a,count);
	printf("%s %d",the_one,strlen(the_one));
	for(current=head;current!=NULL;){
		struct data *temp;
		temp=current;
		current=current->next;
		free(temp);
	}
	//�����˰�malloc�Ķ���ȫ����free�� 
	return 0;
} 

char *find(char *a[],int n){
	char *max=a[0];
	for(int i=0;i<n;i++){
		if(strlen(max)<strlen(a[i]))
		max=a[i];
	}
	
	return max;
}
