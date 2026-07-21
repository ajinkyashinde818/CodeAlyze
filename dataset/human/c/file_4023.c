#include <stdio.h>

int main()
{
	int A, B, K,r;
	scanf("%d %d %d", &A, &B, &K);
	
	int x = 0;
	int y[100];
	
	for(r=0; r<100; r++){
		y[r] = 0;
		}
	
	for(r=0; r<100; r++){
		if(A % (r+1) == 0 && B % (r+1) == 0){
			y[x] = r+1;
			x++;
		}
	}
	
		
	printf("%d", y[x-K]);
	
	return 0;
}
