/*
 ˼·��
 ��ȡ����n��m
 for(int i=0;i<n;i++){}
 ѭ��������ע�Ᵽ��ͷ��Ȼ���ĩβ�ͷ��
 �ٿ�һ��ѭ����ÿ��m�ξ���ȥcurrent��ֱ��prev==current����
 ѭ����ʼ��ʱ��prevΪ����ֵ��currentΪͷ��
 ��ӡcurrent����֮��
 prev=current->next��Ȼ��free��current
 current=prev->next
 */
#include<stdio.h>
#include<stdlib.h>
#define NDEBUG
struct Joseph{
    int number;
    struct Joseph *next;
};
int main(void){
    int n,m;

    struct Joseph *current,*prev,*head=NULL;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        current=(struct Joseph *) malloc(sizeof(struct Joseph));
        if(head==NULL){
            head=current;
        }
        else{
            prev->next=current;
        }
        current->number=i+1;
        prev=current;
    }
    prev=current;
    current->next=head;
    current=head;
#ifdef DEBUG
    for(int i=0;i<n+1;i++){
        printf("%d ",current->number);
        current=current->next;
    }
    //It is all OK till here.
#endif
    int count=0;//ͳ��һ���������ٸ�
    for(int i=1;prev!=current;i++){
        if(!(i%m)){//���i��m����
            printf("%d",current->number);
            prev->next=current->next;
            free(current);
            current=prev->next;
            count++;
            if(count==n-1){
                putchar('\n');
            }
            else{
                putchar(' ');
            }
        }
        else{
            prev=current;
            current=current->next;
        }
    }

    printf("%d",current->number);
    free(current);
    return 0;
}

