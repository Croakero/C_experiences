/*
˼·��
������е���˼���е���˼
�ȰѾ������m��n�ж�ά�����a[m][n]��
�ҵĽ�������һ��ָ����������һһά�����ָ��ptr 
�����ҾͿ��������ָ�����������ƶ��ˡ� 
������ָ���һ�е�һ�У�ȡ����ptr[0]��
Ȼ��ptr++��ȡ0��ptr--��ȡ1��
�����а�����һЩ����δ���ֵ���ѧ����
�����밡�������������ptr+1û������ȥ����������ô�ж��أ�
ÿ�ζ�ptr++��ʱ��һ��������p���ŵ�������ʼֵΪ0��
�����������m-1����ô��ʱ����ptr++�����q++,ptr[q+1]
Ȼ��ptr--��q++ֱ��q��n-1����ȥ
********** �Դ�֮�� 
�۲쵽Zɨ����Կ��Է�Ϊ�������̣�һ����������ɨ����̣�
һ����������ɨ����ͬ��С��б��i�Σ����й���������ɨ�衣
 �Ѳ�ͬ����������Ϊ������Ȼ��ٿ�ָ���ƶ�������Ҫָ������ô�ߵ����ܡ�
 ��ȡ�Ĵ�ӡ�������ƶ����ӡ 
*/
#include<stdio.h>
//����Щ������������ֵ��������Ŀǰ��λ�ã�������Ҫ�ѷ���ֵ������ǰλ��
//�����⣬ָ�벻��仯,��Ҫ�ú� 
#ifdef aDEBUG 
int upright(int (*ptr)[],int num);//���Ϸ��ƶ�
int downleft(int (*ptr)[],int num);//���·��ƶ�
int right(int (*ptr)[],int num);//����һ����λ 
int down(int (*ptr)[],int num);//����һ����λ 
#endif
#define UPRIGHT ptr--,oi++,printf("%d ",*((*ptr)+oi))
#define DOWNLEFT ptr++,oi--,printf("%d ",*((*ptr)+oi))
#define DOWN ptr++,printf("%d ",*((*ptr)+oi))
#define RIGHT oi++,printf("%d ",*((*ptr)+oi))

int main(void){
	int m,n;
	int oi=0;//�����ж�Ŀǰ������ 
	scanf("%d%d",&m,&n);//m��n��
	int arr[m][n];//�����Ϊ
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);//ɨ���ά���� 
		}
	}
	int (*ptr)[n]=&arr[0];//ptr�ǵ�һ�е�һ��
	int j=1;//����б�����������
	printf("%d ",(*ptr)[0]);
	if(m>=n){//��m>=nʱ
		int flag=1;/*���� б���� ���� б���� �ң���˫��һ����������*/
		for(int i=0;i<n-1;i++,flag++){//ѭ��m-1�Σ�ÿ����������
			if(flag%2){//���flag�ǵ���
                RIGHT;
				for(int k=0;k<j;k++){//�����ƶ�j��
				    DOWNLEFT;
				}
			}
			else{//���flag��˫��
                DOWN;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j++;//ע�⣬j׼��������һ�α仯�����˳���ѭ��������һ����ʱ����Ҫj--
        }
		j--;//��jƥ���ʱ��б��ɨ�����
        for(int i=0;i<m-n;i++,flag++){//б�߲���ɨ��
            if(flag%2){//���flag�ǵ���
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
            if(flag%2){//���flag�ǵ���
                DOWN;
                for(int k=0;k<j;k++){//�����ƶ�j��
                    DOWNLEFT;
                }
            }
            else{//���flag��˫��
                RIGHT;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j--;
        }
	}
    else{
        int flag=1;/*���� б���� ���� б���� �ң���˫��һ����������*/
        for(int i=0;i<m-1;i++,flag++){//ѭ��m-1�Σ�ÿ����������
            if(flag%2){//���flag�ǵ���
                RIGHT;
                for(int k=0;k<j;k++){//�����ƶ�j��
                    DOWNLEFT;
                }
            }
            else{//���flag��˫��
                DOWN;
                for(int k=0;k<j;k++) {
                    UPRIGHT;
                }
            }
            j++;//ע�⣬j׼��������һ�α仯�����˳���ѭ��������һ����ʱ����Ҫj--
        }
        j--;//��jƥ���ʱ��б��ɨ�����
        for(int i=0;i<n-m;i++,flag++){//б�߲���ɨ��
            if(flag%2){//���flag�ǵ���
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
            if(flag%2){//���flag�ǵ���
                DOWN;
                for(int k=0;k<j;k++){//�����ƶ�j��
                    DOWNLEFT;
                }
            }
            else{//���flag��˫��
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
