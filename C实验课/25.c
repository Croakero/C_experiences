/*
 思路：
 读取输入n和m
 for(int i=0;i<n;i++){}
 循环开链表，注意保留头，然后把末尾搭到头上
 再开一个循环，每隔m次就消去current，直到prev==current结束
 循环开始的时候prev为最后的值，current为头；
 打印current，那之后
 prev=current->next，然后free掉current
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
    int count=0;//统计一共下来多少个
    for(int i=1;prev!=current;i++){
        if(!(i%m)){//如果i被m整除
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

