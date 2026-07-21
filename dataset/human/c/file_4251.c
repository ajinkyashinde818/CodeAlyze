#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P 1000000007

int main(void){
	int n, m, i;
	char a[100001];
	memset(a, 0, sizeof(a));
	int d[100001];
	scanf("%d%d", &n, &m);
	for(i=0; i<m; i++){
		int A;
		scanf("%d", &A);
		a[A]=1;
	}
	d[0]=1;
	d[1]=(a[1]==0?1:0);
	for(i=2; i<=n; i++){
		if(a[i]==0){
			d[i]=(d[i-2]+d[i-1])%P;
		}else d[i]=0;
	}
	printf("%d\n", d[n]);
}
