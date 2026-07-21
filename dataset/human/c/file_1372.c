#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	int n, m, i;
	char a[200000], b[200000];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%d%d", &n, &m);
	char f=0;
	for(i=0; i<m; i++){
		int A, B;
		scanf("%d%d", &A, &B); A--; B--;
		if(A==0){
			a[B]=1;
			if(b[B]!=0){f=1; break;}
		}
		if(B==n-1){
			b[A]=1;
			if(a[A]!=0){f=1; break;}
		}
	}
	puts(f!=0?"POSSIBLE":"IMPOSSIBLE");
}
