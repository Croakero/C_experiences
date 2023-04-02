#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/*
咱不各美其美了，直接安排一个字符指针，alloc一个值，然后循环读取，再realloc读取直到读完
算了，temp1000字符数组，多用点内存。 
暴力，暴力就完事了
给这个大数组一个1000大小的新数组 
用current指针，strstr查找，找到的话strncat，cat这个指针和上次找到相差的位置
这个指针移动 strlen目的单词的长度，然后strcpy把新单词给放到目标的里面，current继续读取
找到的话strcat到---循环
直到读取到'\0'为止 
*/


#define SIZE 1000
#define SSIZE 10
#define NDEBUG
int main(void){
#ifdef NDEBUG
    char alter[SSIZE],target[SSIZE];
    scanf("%s%s",target,alter);
    FILE*fp=fopen("EXP/exp801/source.txt","r");
    char big[SIZE]={'\0'};//暂时存放
    char towrite[SIZE]={'\0'};//准备往文件写入的内容
    fgets(big,SIZE,fp); //现在内容全部读取到了这个大数组里
    char *current=big,*find=NULL;//一个变动，一个寻找,在big中移动
    char *currentw=towrite;//currentw在towrite中移动
    int step=0;//find到现在走过的长度
    int count=0;//count统计替换的次数
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
            strncat(currentw, current, step);//把目的单词之前的给放进去
            currentw += step;//currentw移动
            current = find;
            current += strlen(target);//current跳过目的单词
            strcat(currentw, alter); //currentw里面写入原单词
            currentw += strlen(alter);//currentw在写入新单词后越过新单词}
        }
        else{
            find+=strlen(target);
            step=find-current;
            strncat(currentw,current,step);
            current=find;
        }
    }
        //如果找不到，将current后面的东西全部给currentw写进去
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
