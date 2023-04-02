#include<stdio.h>
int CMT(const int mx [][4]);
int m;
int num=0;
int flag=0;
int main(void){
	scanf("%d",&m);
	int mtx[m][4];
	for(int i=0;i<m;i++){
		for(int j=0;j<4;j++){
		scanf(" %d",&mtx[i][j]); 
		}
	}
	CMT(mtx); 
	return 0;
	} 

int CMT(const int mx[][4]){
	//printf("%d",flag);
	int n=4;
	int pt[m*4];
	//printf("%d",flag);
	if(flag==0){
		for(int a=0;a<m;a++){
			pt[num]=mx[a][0];
			num++;
		}(flag)++;
		printf("%d",flag);
		int CMT(const int mx[][4]);
	}
	else if(flag==1){
		//printf("%d",flag);
		for(int b=0;b<4;b++){
			pt[num]=mx[m-1][b];
			num++;
		}(flag)++;
		printf("%d",flag);
		int CMT(const int mx[][4]);
		//printf("%d",flag);
	}
	else if(flag==2){
		for(int c=m-1;c>=0;c--){
			pt[num]=mx[c][n-1];
			num++;
		}
		(flag)++;
		int CMT(const int mx[][4]);
		//printf("%d",flag);
	}
	else if(flag==3){
		for(int d=n-1;d>0;d--){
			pt[num]=mx[0][d];
			num++;
		}
		(flag)++;
			int CMT(const int mx[][4]);
	}
	else if(flag==4){
		for(int e=0;e<m-1;e++){
			pt[num]=mx[e][1];
			num++;
		}
		(flag)++;
			int CMT(const int mx[][4]);
	}
	else if(flag==5){
		for(int f=1;f<n-1;f++){
			pt[num]=mx[f][m-2];
			num++;
		}(flag)++;
			int CMT(const int mx[][4]);
	}
	else if(flag==6){
		for(int g=m-2;g>0;g--){
			pt[num]=mx[g][2];
			num++;
		}(flag)++;
	}
	if(flag==7){
		for(int p=0;p<m*n;p++)
		printf("%d",pt[p]);
	}
}
