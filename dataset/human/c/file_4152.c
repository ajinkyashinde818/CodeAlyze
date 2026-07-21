#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define FOR(i,m,n) for(i=m;i<n;i++)

int main(void)
{
	int a,b,c,i,x=0,y;
	scanf("%d %d %d",&a,&b,&c);
	for(i=110;i>0;i--){
		if(a%i==0){
			if(b%i==0){
				x++;
			}
		}
		if(x==c){
			y=i;
			break;
		}
	}
	printf("%d",y);
	return 0;
}
