#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRLEN 300
#define FUCKEDU 114
int j=0;
int main()
{
#ifdef FUCKEDU
	FILE *fp=fopen("source.txt","r+");  
    char content[STRLEN];
    char needle[STRLEN];
    char replace[STRLEN];
    char *p;
    int len;
    char words[53];
    int i;
    for(i='a',p=words;i<='z';i++)
    {
        *p++=i;
    }
    
    for(i='A',p=words+26;i<='Z';i++)
    {
        *p++=i;
    }
    words[52]='\0';
    
    fgets(content,STRLEN,fp);   //1从文件获取 
    scanf("%s",needle);
    scanf("%s",replace);
    content[strcspn(content,"\r\n")]='\0';
    needle[strcspn(needle,"\r\n")]='\0';
    replace[strcspn(replace,"\r\n")]='\0';
    if(strlen(needle)!=strspn(needle,words))
    {
        puts("注意：查找的单词中有非字母，可能出错。");
    }
    if(strlen(replace)!=strspn(replace,words))
    {
        puts("注意：替换的单词中有非字母，可能出错。");
    }
    puts("替换结果：");
    p=content;
    fclose(fp);
    fp=fopen("source.txt","w+");  //2空白模式打开 
    
    while(*p){
        len=strspn(p,words);
        if(len){
        if(strncmp(p,needle,len))
        {
            fprintf(fp,"%.*s",len,p); 
                               //存储进文件 
        }
        else
        {
            fprintf(fp,"%s",replace); //
			j++;//
        }
        p=p+len;
        }
        else
        {
            fprintf(fp,"%c",*p);   //
            p++;
        }
    }
    
    printf("%d\n",j);
	char get[STRLEN]; 
	rewind(fp);
    while(fgets(get,STRLEN,fp)!=NULL)
    {
    	fputs(get,stdout);
	}
      
#endif
#ifndef FUCKEDU
	FILE *fp=fopen("source.txt","w+");
	fprintf(fp,"May you have enough happiness to make you sweet, enough trials to make you strong, enough sorrow to keep you human, enough hope to make you happy? Always put yourself in others' shoes. If you feel that it hurts you, it probably hurts the other person, too.");      
	fclose(fp);
#endif
    return 0;

}

