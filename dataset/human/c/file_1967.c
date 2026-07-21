#include <stdio.h>
#define MN 20
#define MA 50

int manzoku(int A[], int B[], int C[], int* p)
{
	int prev, score, num, i;
	prev = A[0];
	score = B[prev - 1];

	for(i = 1; i < *p; i++){
		num = A[i];
		score += B[num - 1];
		if(num == prev + 1){
			score += C[prev - 1];
		}
		prev = num;
	}
	return score;
}

int main(void)
{
	int i, n, *p;

	scanf("%d", &n);
	p = &n;

	int A[MN], B[MA], C[MA];

	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	for(i = 0; i < n; i++){
		scanf("%d", &B[i]);
	}

	for(i = 0; i < n - 1; i++){
		scanf("%d", &C[i]);
	}

	printf("%d", manzoku(A,B,C,p));

	return 0;
}
