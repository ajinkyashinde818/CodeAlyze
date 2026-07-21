#include <stdio.h>

int main(void){
	int N,K;
	int size[100000];
	int count;
	int i;
	scanf("%d %d",&N, &K);
	for(i=0; i<N; i++)
		scanf("%d",&size[i]);

	count=0;
	for(i=0; i<N; i++)
		if(size[i] >= K) count++;

	printf("%d\n", count);
}
