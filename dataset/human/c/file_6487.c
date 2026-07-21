#include<stdio.h>

int main(void)
{
	int i, N;
	int maxv, minv;
	int R[200000] = {0};
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) {
        scanf("%d", &R[i]);
    }
	
	maxv = -2000000000;
	minv = R[0];
	
	for(i = 1; i < N; i++) {
		if(maxv < (R[i] - minv)) {
			maxv = (R[i] - minv);
		} if(minv > R[i]) {
			minv = R[i];
		}
	}
	
	printf("%d\n", maxv);
	
	return 0;
	
}
