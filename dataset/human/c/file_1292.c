#include <stdio.h>
#include <math.h>
int main(void){
	int i,j,p[8],m[8][8],sum,ans,sss;
	m[0][0]=1;m[0][1]=2;m[0][2]=1;m[0][3]=2;m[0][4]=1;m[0][5]=4;m[0][6]=1;m[0][7]=4;
	for(i=0;i<8;i++){
		m[1][(i+6)%8]=m[0][i];
		m[2][(i+2)%8]=m[0][i];
		m[3][(i+4)%8]=m[0][i];
		m[4][(i+7)%8]=m[0][i];
		m[5][(i+5)%8]=m[0][i];
		m[6][(i+1)%8]=m[0][i];
		m[7][(i+3)%8]=m[0][i];
	}
	while(scanf("%d %d %d %d %d %d %d %d",&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6],&p[7])!=EOF){
		sss=9999999;
		for(i=0;i<8;i++){
			sum=0;
			for(j=0;j<8;j++){if(p[j]-m[i][j]>0)sum+=p[j]-m[i][j];}
			if(sum<sss){ans=i;sss=sum;}
		}
		for(i=0;i<8;i++){
			printf("%d",m[ans][i]);
			if(i<7)printf(" "); else printf("\n");
		}
	}
	return 0;
}
