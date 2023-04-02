#include <stdio.h>
 
 int main(void)
 {
     int i=-1;
     char j;
     scanf("%x",&i);
     j=getchar(); 
     
    if(i>=0&&i<=15){ 
    printf("%d",i);
    } 
    else printf("%c",j);
    return 0;
}
