/*
思路：
fopen()打开文件，然后用fgets函数一行一行写入，
开一个大一点的数组保证每行不越界。(我现在会无冗余读取了哦耶)
要用strstr()函数，首先查找目标单词，
如果返回的不是空指针的话，那么继续查找，如果找到的话，
打印前面的内容，然后 
我总觉得这个方法很笨拙，不，在后来的我看很聪明，我爱指针 。 
有没有打印到指针指定位置的函数，我只需要把没用的变成'\0'就成了，ok 
噢，用strncopy()函数,那个最后的n用两个指针相减得出来。
把那个串前面的内容全部都用strncpy函数复制到某个串temp，
传回来的指针再移动那个字符串的长度，然后接着查找
*/

#include<string.h>
#include<stdio.h>
#define SIZE 100
int main(void){
	char read[SIZE]={'\0'};//从文件读取一行输入 
	char target[10]={'\0'};//目标词汇 
	char source[10]={'\0'};//原始词汇 
	FILE *fp;//打开文件 
	fp=fopen("source.txt","r+");
	
	while(1){
		char temp[SIZE]={'\0'};
		if(fgets(temp,SIZE,fp)==NULL) break;
		char putin[strlen(temp)+1];
		strcpy(putin,temp);//现在putin数组里无冗余地存储了我想要的东西 
		char *find=NULL;
		char *anchor;//锚点，负责移动到新位置 
		while((find=strstr(putin,source)))
	}
} 
