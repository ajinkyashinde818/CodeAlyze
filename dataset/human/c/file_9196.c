#include <stdio.h>
#define Fori(g) for(int i=0;i<g;i++)
#define	Forj(g) for(int j=0;j<g;j++)
#define min(a,b) return (a<b)?a:b
#define max(a,b) return (a<b)?b:a
#define gcd(a,b) return (!b)?a:gcd(b,a%b)

int main(){
	int n,k,count=0;
	scanf("%d%d",&n,&k);
	int h[n];
	Fori(n)scanf("%d",&h[i]);

	Fori(n)if(h[i]>=k)count++;

	printf("%d\n",count);
	return 0;
}
