#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/*
�۲����������ˣ�ֱ�Ӱ���һ���ַ�ָ�룬allocһ��ֵ��Ȼ��ѭ����ȡ����realloc��ȡֱ������
���ˣ�temp1000�ַ����飬���õ��ڴ档 
������������������
�����������һ��1000��С�������� 
��currentָ�룬strstr���ң��ҵ��Ļ�strncat��cat���ָ����ϴ��ҵ�����λ��
���ָ���ƶ� strlenĿ�ĵ��ʵĳ��ȣ�Ȼ��strcpy���µ��ʸ��ŵ�Ŀ������棬current������ȡ
�ҵ��Ļ�strcat��---ѭ��
ֱ����ȡ��'\0'Ϊֹ 
*/


#define SIZE 1000
#define SSIZE 10
#define NDEBUG
int main(void){
#ifdef NDEBUG
    char alter[SSIZE],target[SSIZE];
    scanf("%s%s",target,alter);
    FILE*fp=fopen("EXP/exp801/source.txt","r");
    char big[SIZE]={'\0'};//��ʱ���
    char towrite[SIZE]={'\0'};//׼�����ļ�д�������
    fgets(big,SIZE,fp); //��������ȫ����ȡ���������������
    char *current=big,*find=NULL;//һ���䶯��һ��Ѱ��,��big���ƶ�
    char *currentw=towrite;//currentw��towrite���ƶ�
    int step=0;//find�������߹��ĳ���
    int count=0;//countͳ���滻�Ĵ���
    while((find=strstr(current,target))!=NULL) {
        char *temp = find;
        int i = 0;
        while (*temp != EOF && i <= strlen(target) + 1) {
            temp++;
            i++;
        }
        if ((isspace(*(find + strlen(target))) || ispunct(*(find + strlen(target)))) || i < strlen(target) + 1) {
            count++;
            step = find - current;
            strncat(currentw, current, step);//��Ŀ�ĵ���֮ǰ�ĸ��Ž�ȥ
            currentw += step;//currentw�ƶ�
            current = find;
            current += strlen(target);//current����Ŀ�ĵ���
            strcat(currentw, alter); //currentw����д��ԭ����
            currentw += strlen(alter);//currentw��д���µ��ʺ�Խ���µ���}
        }
        else{
            find+=strlen(target);
            step=find-current;
            strncat(currentw,current,step);
            current=find;
        }
    }
        //����Ҳ�������current����Ķ���ȫ����currentwд��ȥ
        strcat(currentw, current);
        fclose(fp);
        fp = fopen("EXP/exp801/source.txt", "w+");
        fputs(towrite, fp);
        fclose(fp);
        printf("%d\n", count);
        printf("%s", towrite);
#endif
#ifdef NDEBUG
    char back[SIZE]={"May you have enough happiness to make you sweet, enough trials to make you strong, enough sorrow to keep you human, enough hope to make you happy? Always put yourself in others' shoes. If you feel that it hurts you, it probably hurts the other person, too."};
    fp=fopen("EXP/exp801/source.txt","w+");
    fputs(back,fp);
    fclose(fp);
#endif
    return 0;

}

#ifdef FUCK
&&(isspace(*(find-1))||ispunct(*(find-1)))&&(isspace(*(find+1))||ispunct(*(find+1)))
#endif
