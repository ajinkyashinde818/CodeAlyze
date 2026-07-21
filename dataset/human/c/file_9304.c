#include <stdio.h>

int main(void)
{
	int N, i, k, h[100000], cnt=0;
	
	scanf("%d %d", &N, &k);
	
	for(i=0; i<N; i++){
		scanf("%d", &h[i]);
		if(h[i]>=k){ cnt++; }
	}
	
	printf("%d", cnt);
	
	return 0;
}
