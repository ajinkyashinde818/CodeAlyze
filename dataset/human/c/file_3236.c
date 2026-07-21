#include<stdio.h>
#include<string.h>
#include<math.h>
#define rep(i,n) for(i=0; i<n; i++)

int main(void)
{
	int i, n, k, d, min;
	scanf("%d%d", &k, &n);
	int a[n];
	rep(i,n) scanf("%d", &a[i]);

	min = a[n-1]-a[0];
	for(i=1; i<n; i++){
		d = k-(a[i]-a[i-1]);
		if(d<min){
			min = d;
		}
	}
	printf("%d", min);
	return 0;
}
