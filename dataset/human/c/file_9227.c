#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, k, i;
	int h[100000];
	int x;
	x=0;
	scanf("%d %d", &n, &k);
	for(i=0;i<n;i++){
		scanf("%d", &h[i]);
		if(h[i]>=k){
			x=x+1;
		}
	}
	printf("%d", x);
	return 0;
}
