#include <stdio.h>
int main()
{
int n=10000;
int r,j,i;
for(i=1;i<=n; i++){
r = 0;
for(j=1;j<i;j++){
if(i%j == 0){
r = r + j;
}
}
if(r == i){
printf("the result is:%d\n",r);
}
}
return 0;
}
