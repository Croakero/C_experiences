/*
˼·��
��������һ��n*80�Ķ�ά���飬ɨ����Щ�ַ�
Ȼ���������鴫��delete����������n 
delete����
**********
�������̫������
������main��������ɨ��n����һ��forѭ��
��һ��nԪ���ַ���ָ�����飬���ڵ�[i]��ָ��Ԫ�أ�
�����ָ��mallocһ���ֽڵĵ�λ,�����ȡҪ�ٿ�һ��ѭ��
����getchar()�������ݣ�ֱ������'\0'�ڲ�ѭ������ 
ɨ�������һ��forѭ��������ֱ����forѭ���ڲ�ʵ��
ѭ������ɾ��������������������ָ������ĵ�i����Ա
Ȼ�����������ڲ���ϸ��
delete������Ҫ��һ�������ַ�ָ�뷵��ֵ���͵ĺ��� 
�ȴ���ʼλ�ã�Ȼ����ָ��������
���isblank()���������棬�Ͱ���ʼλ������Ϊָ�봦��
ֱ�������ǿո��ˮƽ�Ʊ��Ϊֹ
Ȼ��������ָ�룬һ��prevһ��current(current���Ѿ�������ָ��)����Ҫ��¼ʣ�µ����ݳ��� 
���prev��current�����ݶ�ָ���˿ո���ô������ո��Ϊ'\0'������ѭ���ƶ�
yikesou 
**********
����������Ϊʲô�������������Ϳ���
�ף� ��Ϊʲô����������������������
�޲��У����鲻��Խ��ĳ���ط�ָ�������ط����һ����ع��ɣ������� 
�������ղŵ�˼·
�޲��Բ��ԣ�ָ���ַ������鲻��ָ��ṹ�����飬�ûص�����
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
		a[i]=(char *)malloc(sizeof(char));//������һ���ڴ� 
		for(j=0;(c=getchar())!='\n';j++){
			a[i]=realloc(a[i],j+1);
			a[i][j]=c;
		}
		a[i]=realloc(a[i],j+1);//ԭ����ֻ��j+1���Ҳ��Ż��з�������̱�⡣��һ��'\0' 
		a[i][j]='\0';
	}
	//�Ⲩ���������������������ȡ��Ȼ��Ч��
	/*
	a debug boi
	for(int i=0;i<n;i++){
		puts(a[i]);
	}
	*/
	//�����뵽�������ȡ�ַ������ȵķ�����strlen������ 
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
	for(int isstart=0;*ptr!='\0';ptr++){//isstart�����ж��Ƿ��Ѿ���ʼ�ַ��� 
		if(isstart==0&&isblank(*ptr)){
			head++;
		}
		else if(isstart==0){
			isstart=1;
		}
		if(isstart==1){
			if(prev==NULL){
				prev=ptr-1;//�������Խ�磬�����������⣬���ڵ�prev��ptr�����ܾ���ָ��ո� ����Ϊ�����Ѿ�û�пո��� 
			}
			if(*prev==' '&&*ptr==' '){
				while(*ptr==' '){
					int num=strlen(ptr)+1;//������֮��ĳ���
					char* current=ptr;//����һ��ָ��ָ������λ�� 
					for(int i=0;i<num;i++){
						*current=*(current+1);
						current++;
					}
					*(current-1)='\0';
				}//ת�˺ö�Σ����Ǵ�ʱprevû�б䣬ptrָ�������һ���ַ� 
			}
		}
		if(prev!=NULL) prev++;
	}
	return head;
}
