#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//scanf("%d",&x);
//printf("%d",x);
//for(i=0;i<N;i++){  }
//if( == ){  }else{  }
//while( ){  }

/*
int N, i;
int H[100];
scanf("%d", &N);
for (i = 0; i < N; i++) scanf("%s", &H[i]);
*/

int main()
{
	int N, i, S1 = 0, S2 = 0;;
	int A[20];
	int B[50];
	int C[50];
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	for (i = 0; i < N; i++) scanf("%d", &B[i]);
	for (i = 0; i < N-1; i++) scanf("%d", &C[i]);

	for (i = 0; i < N; i++) {
		S1 += B[i];
	}

	for (i = 0; i < N; i++) {
		if (A[i] + 1 == A[i + 1]) {
			int t = A[i];
			S2 += C[t-1];
		}
	}

	printf("%d", S2+S1);
}
