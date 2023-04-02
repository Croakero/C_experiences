#include<stdio.h>
#include<math.h>
#define S(a,b,c) (a+b+c)/2
#define AREA(s,a,b,c) pow(s*(s-a)*(s-b)*(s-c),0.5)
int main(void){
	double a,b,c,s,area;
	scanf("%lf%lf%lf",&a,&b,&c);
	s=S(a,b,c);
	area=AREA(s,a,b,c);
	printf("s=%.2lf\narea=%.2lf",s,area);
	return 0;
}
