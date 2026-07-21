#include<stdio.h>
#include<math.h>
int sqr(int x){return x*x;}
bool sq(int x){return sqr(sqrt(x))==x;}
int p[510][510];
int main(){
	int n,k,i,j,M;
	scanf("%d",&n);
	if(!sq(n*8+1)){
		puts("No");
		return 0;
	}
	k=(1+(int)sqrt(n*8+1))/2;
	for(i=1;i<k;i++){
		for(j=1;j<=i;j++)p[i][j]=++M;
	}
	printf("Yes\n%d\n",k);
	for(i=1;i<k;i++){
		printf("%d ",k-1);
		for(j=1;j<=i;j++)printf("%d ",p[i][j]);
		for(j=i+1;j<k;j++)printf("%d ",p[j][i]);
		putchar('\n');
	}
	printf("%d ",k-1);
	for(i=1;i<k;i++)printf("%d ",p[i][i]);
}
