#include "stdio.h"

int N, D, X;

int main(int argc, char* argv[])
{
	int ans=0;
	int i;
	int a;

	scanf("%d%d%d", &N, &D, &X);

	ans += X;
	for(i=0;i<N;i++){
		scanf("%d", &a);
		ans += (D-1)/a + 1;
	}


	printf("%d\n", ans);
	return 0;
}
