/*
˼·����һ����ά���飬��ʮ�ţ�ÿ�������λ
�һ��ǿ�һ��һά�ṹ���飬100��Ԫ�أ��ṹ�ں��Ƿ���������λ����Ԫ�� 
��Ҫ����һ��ѭ�����ṹ��ֵ 
******************** 
һ���������ܹ������n�����ڲ���ڲ�ѭ���жϣ�����Ϊn�պ���Ҫ�ж�5-n�Σ���1��ʼ
�ڲ�i,j��i��1��20�����ڶ�ʮ��j��1��5�������壬����i*j-1Ԫ��
��jѭ����ʵ���ж���λ���ڽ���j֮ǰ��ֵcount=0;ÿ����һ�����Բ����ģ���0����count++����count==buy��ʱ���˳�ѭ��
Ȼ��������ټ�¼total,�ٿ�һ��ѭ������i*j-1��i*j-1+count��isblankȫ����Ϊ0
total==TOTAL�Ļ������������û�������Ҵ�ʱ�Ѿ�������λĩβ�����ؿ�һ��ѭ��,
********************
���ѭ���������ŵ� 
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
	int mule=1;//mule�����ڽ�������ѭ���б�ʾѭ������ 
	for(i=0;i<ROW;i++){
		for(j=0;j<EACH;j++){						//�������⣬������20 
			ptr->first=mule;
			if(j!=4) 
			ptr->No[0]='A'+j;
			else
			ptr->No[0]='F';//Ϊɶ��·��Ū��E�� 
			ptr->No[1]='\0';
			ptr->isblank=1;
			ptr++;
		}
			mule++;
	}
	ptr=ar;//����ָ�� 
	select(ptr);
	
	return 0;
}

void select(struct seats * ptr){
	int num;//����������ٴ�Ʊ 
	scanf("%d",&num);
	int count;//�����ܷ���Ʊ 
	for(int k=0;k<num;k++){//������ѭ����ȡ 
		int buy;
		int total=0;//����ε�һЩƱ�������˶��ٴ� 
		scanf("%d",&buy);//��������Ʊ 
		int i,j;//������λ���� 
		for(i=1;i<=ROW;i++){//���������� 
			count=0;//count���ƿ����������Ʊ 
			for(j=1;j<=EACH;j++){//����ÿ��������λ 
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
		int m=0;//m���Ѿ����Ʊ�� 
		if(total!=TOTAL){
			for(int l=total-count;m<buy;m++){//������� 
				printf("%d%s",(ptr+l+m)->first,(ptr+l+m)->No);//������� 
				(ptr+l+m)->isblank=0;//��λ������Ϊ�����
				if(m!=buy-1){
					putchar(' ');
				}
				else{
					putchar('\n');
				}
			}
		}
		else{//����Ѿ�������һ�ٴλ�û���ҵ����� 
			int done=0;//�Ѿ����Ʊ�� 
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
