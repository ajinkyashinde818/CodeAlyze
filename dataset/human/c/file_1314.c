#include <stdio.h>
int main(){
	int n,m,c[200002],i,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<200002;i++)
	c[i]=0;
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a==1)
		c[b]++;
		if(b==n)
		c[a]++;
	}
	for(i=1;i<=n;i++){
		if(c[i]==2){
		   printf("POSSIBLE");
		   return 0;
		 }
	}
	printf("IMPOSSIBLE");
    return 0;
 }
