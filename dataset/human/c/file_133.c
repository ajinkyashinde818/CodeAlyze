#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define FOR(i,m,n) for(i=m;i<n;i++)

int main(void)
{
	int a,b,c,d,i,j,k,x=0,e,f;
	if(a<b){
		a=e;
		a=b;
		b=e;
	}
	if(a<c){
		a=e;
		a=c;
		c=e;
	}
	if(b<c){
		b=e;
		b=c;
		c=e;
    }
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(i=0;i<d+1;i++){
		for(j=0;j<d-a*i+1;j++){
			if(a*i+b*j>d) break;
			else if((d-a*i-b*j)%c==0){
				x++;
			}
		}
	}
	printf("%d",x);
	return 0;
}
