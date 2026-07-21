#include<stdio.h>
#include<math.h>
int main(){
	int n,k,i,j,m,x[10001][2],p;
	scanf("%d%d%d",&n,&k,&m);
	for(i=0;i<m;i++)scanf("%d%d",&x[i][0],&x[i][1]);
	for(i=1;i<m;i++){
		if((x[i][0]>x[i-1][0]&&x[i][1]>x[i-1][1])||(x[i-1][0]>x[i][0]&&x[i-1][1]>x[i][1])){
			if(abs(x[i][0]-x[i-1][0])>abs(x[i][1]-x[i-1][1]))p-=abs(x[i][1]-x[i-1][1]);
			else p-=abs(x[i][0]-x[i-1][0]);
		}
		p+=abs(x[i][0]-x[i-1][0])+abs(x[i][1]-x[i-1][1]);
	}
	printf("%d\n",p);
	return 0;
}
