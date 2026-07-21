#include <stdio.h>
int main(void){
	int n,m,i;
	scanf("%d%d",&n,&m);
	int a,b,b1[n],b2[n];
	for(i=0;i<n;i++){b1[i]=0;b2[i]=0;}
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a==1)	b1[b] = 1;
		if(b==n)	b2[a] = 1;
	}
	for(i=0;i<n;i++){
		if(b1[i]==1 && b2[i]==1){
			printf("POSSIBLE");
			return 0;
		}
	}
	
	printf("IMPOSSIBLE");
	return 0;
}
