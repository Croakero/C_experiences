/*
思路：
先声明一个文件指针，打开文件，然后用getc()来判断
字符数就是isalnum()来判断，如果isinword==0时遇到空格或者ispunct，
那么isinword变成1，(刚开始isinword要设置为1)，如果
isinword==1的时候遇到空格或者ispunct，则将其设置为0，单词数+1
如果遇到了句号，那么句子+1，这个判断应该是独立的判断 
开始！ 
*/
#include<ctype.h>
#include<stdio.h>

int main(void){
	char c,prev;
	int inword=0,characters=0,words=0,sentences=0;
	int out=0;
	FILE *fp;
	char temp[40]={'\0'};
	scanf("%s",temp);
	fp=fopen(temp,"r");
	while((c=getc(fp))!=EOF){
		out++;
		if(!isspace(c)&&!inword){//如果是空白字符并且没在单词内 
			inword=1;
			words++;
		}
		if(isspace(c)&&inword){//如果是空白字符并且在单词内，单词结束 
			inword=0;
		}
		if(c=='.'){
			sentences++;
		}
		if(isspace(c)){
			characters++;
		}
	}
	characters=out-characters;
	fclose(fp);
	printf("Characters: %d\n",characters);
	printf("Words: %d\n",words);
	printf("Sentences: %d",sentences);
	return 0;
}

