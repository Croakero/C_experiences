 #include <stdio.h>
 #include <math.h>
 int digit(int n, int k);
 int main(void)
 {
     int n,k;
     
     scanf("%d%d", &n, &k);
     printf("%d", digit(n,k));
     return 0;
 }
 int digit(int n,int k){
 	int re;
 	if(n<pow(10,k-1))
 	return -1;
 	else{
 		re=n/(pow(10,k-1));
 		re=re%10;
 		return re;
	 }
 }
