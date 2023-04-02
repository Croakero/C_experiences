/*
˼·��
�����ṹ���ں�һ��ѧ�ţ�һ���������ĸ��ɼ���һ��ָ��
��һ����̬��������ͳ��һ���߹�����Ŀ���� 
main()����ѭ����ȡ�˵����ݣ�switch���ֹ����


����ס�˱���ס�ˣ�ֻ��һ������������ǳ�����ʵ�֣��Ҿ�����һ�����������������Ӧ��ָ��
Ȼ����������������������ָ��
���У��ұ���ֻʹ��һ������
 bubble done!15:03
 choose done!16:11
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int number=0;
struct student{
    int number;
    char name [10];
    int E,M,P,C;
    double S;
    struct student * next;
};
void getinfo(struct student *);
void printeinfo(struct student *);
void changeinfo(struct student *);
void average(struct student *);
void printainfo(struct student *);
void cleaninfo(struct student *);
struct student* bubble(struct student *,int select);
struct student * choose(struct student *,int select);
int main(void){
    struct student *head=NULL,*current=NULL;
    int select,n;
    scanf("%d",&select);
    while(select!=0){
        switch (select){
            case 0: cleaninfo(head);
                return 0;
            case 1:
                scanf("%d",&n);
                struct student * current,* prev;
                for(int i=0;i<n;i++){
                    current=(struct student*)malloc(sizeof (struct student));
                    if(head==NULL){
                        head=current;
                    }
                    else {
                        prev->next=current;
                    }
                    scanf("%d%s%d%d%d%d",&current->number,&current->name,&current->E,&current->M,&current->P,&current->C);
                    prev=current;
                    prev->next=NULL;
                    current->S=current->E+current->M+current->P+current->C;
                }
                printf("�����%dλͬѧ�ĳɼ�����\n",n);
                number+=n;
                break;
            case 2: printeinfo(head);
                break;
            case 3: changeinfo(head);
                break;
            case 4: average(head);
                break;
            case 5: printainfo(head);
                break;
            case 6: scanf("%d",&select);
                int temp;
                if(select==0){
                    scanf("%d",&temp);
                    if(temp==0){
                        head=choose(head,select);
                    }
                    else head=bubble(head,select);
                }
                else{
                    if(temp==0){
                        head=choose(head,select);
                    }
                    else{
                        head=bubble(head,select);
                    }
                }
                average(head);
                break;
        }
        while(getchar()!='\n');
        scanf("%d",&select);
    }
    return 0;
}




void printeinfo(struct student *head){
    struct student * current=head;
    while(current!=NULL){
        printf("%d %s %d %d %d %d\n",current->number,current->name,current->E,current->M,current->P,current->C);
        current=current->next;
    }
}

void changeinfo(struct student *head){
    struct student * current=head;
    int find,num;
    char temp[10]={'\0'};
    scanf("%d%d",&find,&num);
    while(current!=NULL){
        if(current->number==find){
            switch(num){
                case 0:
                    scanf("%s",current->name);
                    break;
                case 1:scanf("%d",&current->E);
                    break;
                case 2:scanf("%d",&current->M);
                    break;
                case 3:scanf("%d",&current->P);
                    break;
                case 4:scanf("%d",&current->C);
                    break;
            }
            printf("%d %s %d %d %d %d\n",current->number,current->name,current->E,current->M,current->P,current->C);
        }
        current=current->next;
    }
}

void average(struct student *head){
    struct student * current=head;
    while(current!=NULL){
        current->S=current->E+current->M+current->P+current->C;
        printf("%d %s %.2lf\n",current->number,current->name,(current->S)/4);
        current=current->next;
    }
}

void printainfo(struct student *head){
    struct student * current=head;
    while(current!=NULL){
        current->S=(current->E+current->M+current->P+current->C);
        printf("%d %s %d %.2lf\n",current->number,current->name,(int)current->S,(current->S)/4);
        current=current->next;
    }
}

void cleaninfo(struct student *head){
    struct student *current=head,*temp;
    while(current!=NULL){
        temp=current->next;
        free(current);
        current=temp;
    }
}

struct student* bubble(struct student *head,int selection){//���п��ܽ���ͷ�ڵ㣬����Ҫ����ͷ
    int count=0;
    struct student *current=head,*temp,*head0=head,*anchor,*prev=head;
    while(current->next!=NULL){
        current=head0;
        while(current->next!=NULL){
            if(selection==1){
                if(current==head&&current->S<current->next->S){//����ͷ�ڵ�
                    temp=current->next->next;
                    anchor=current->next;
                    current->next->next=current;
                    current->next=temp;
                    current=anchor;
                    prev=current;
                    head=prev;
                }
                else if (current->S<current->next->S)
                {
                    prev->next=current->next;
                    current->next=current->next->next;
                    prev->next->next=current;
                    current=prev->next;
                }
                if(current==prev){
                    current=current->next;//���û����ô��һ��
                }
                else{
                    prev=current;
                    current=current->next;//������������
                }
            }
            else{
                if(current==prev&&current->S>current->next->S){//����ͷ�ڵ�
                    temp=current->next->next;
                    anchor=current->next;
                    current->next->next=current;
                    current->next=temp;
                    current=anchor;
                    prev=current;
                    head=prev;
                }
                else if (current->S>current->next->S)
                {
                    prev->next=current->next;
                    current->next=current->next->next;
                    prev->next->next=current;
                    current=prev->next;
                }
                if(current==prev){
                    current=current->next;//���û����ô��һ��
                }
                else{
                    prev=current;
                    current=current->next;//������������
                }
            }
        }
        head0=head0->next;
    }
    return head;
}

struct student * choose(struct student *head,int selection){
    /*
     ˼·��
     ����ǳ��Ѹ㣬�����밡
     ��������������
     ���ȱ����������������������ָ�����ǵ�ָ��洢��һ��������
     Ȼ��ѡ���жϣ��������������
     �ٱ���ѡ�񣬽��������������긳ֵ
     ��������ֻ����һ��������Ҫ�Ż�������������
     ͷ�ڵ㴦��
     ���ȼ�¼ͷ�ڵ㣬��head1
     head0->next=head1;
     prev=head1��current=prev->next��
     �ж�������Ȼ��current->next!=NULL
     ���current->S����head0->S������������
     the_one��¼current,the_prev��¼prev
     Ȼ�󽻻�
     ���ѡ�����������ڵ���������ô����ð�ݵ�˼·����
    */
    struct student *current=head,*head1=head,*the_one,*the_prev,*prev;
    struct student *temp,*head0;//head0ָ��head1
    struct student null;
    head0=&null;
    head0->next=head1;
    while(current!=NULL){
        the_one=head1;the_prev=NULL;
        struct student *m=head1;
        if(selection==1){
            while(current!=NULL){
                if(current->S>the_one->S){
                    the_one=current;
                    the_prev=prev;
                }
                prev=current;
                current=current->next;
            }
            if(the_one!=head1&&head1==head){//�����һ��Ҫ���û�
                head=the_one;
            }
            if(the_one!=head1&&head1->next!=the_one) {//���������
                the_prev->next = head1;
                head0->next = the_one;
                temp = the_one->next;
                the_one->next = head1->next;
                head1->next = temp;
                head1 = head0->next;
            }
            else if(the_one!=head1&&head1->next==the_one){//�������
                head0->next=head1->next;
                head1->next=the_one->next;
                head0->next->next=head1;
                head1=head0->next;
            }
        }
        else{
            while(current!=NULL){
                if(current->S<the_one->S){
                    the_one=current;
                    the_prev=prev;
                }
                prev=current;
                current=current->next;
            }
            if(the_one!=head1&&head1==head){//�����һ��Ҫ���û�
                head=the_one;
            }
            if(the_one!=head1&&head1->next!=the_one) {//���������
                the_prev->next = head1;
                head0->next = the_one;
                temp = the_one->next;
                the_one->next = head1->next;
                head1->next = temp;
                head1 = head0->next;
            }
            else if(the_one!=head1&&head1->next==the_one){//�������
                head0->next=head1->next;
                head1->next=the_one->next;
                head0->next->next=head1;
                head1=head0->next;
            }
        }
        head0=head1;
        head1=head1->next;
        current=head1;
        prev=head0;
    }
    return head;
}
