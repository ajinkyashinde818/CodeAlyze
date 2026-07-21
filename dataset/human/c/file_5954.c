#include<stdio.h>
#define N 200000
#define INF 1000000000
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int a[N];

int main(){
	int n,x;
	int maxv=-INF;
	int minx=INF;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(i==0)minx=x;
		else {
			maxv=MAX(maxv,x-minx);
			minx=MIN(x,minx);
		}
	}

	printf("%d\n",maxv);
	
	return 0;
	
}
