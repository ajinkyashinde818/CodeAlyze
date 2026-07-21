#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define FOR(i,m,n) for(i=m;i<n;i++)

int main(void)
{
	int a,b,i;
	char c[11];
	scanf("%d",&a);
	scanf("%s",c);
	scanf("%d",&b);
	for(i=0;i<a;i++){
		if(c[i]!=c[b-1]){
			c[i]='*';
		}
	}
	printf("%s\n",c);
	return 0;
}
