#include<stdio.h>
#include<string.h> 
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	int r;
	int h[N];
	int p=0;
	
	for(r=0; r<N; r++){
		scanf("%d", &h[r]);
		if(h[r] >= K) p++;
	}
	
	printf("%d", p);

}
