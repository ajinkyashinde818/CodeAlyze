#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int N;
	long K;
	int *A;
	int *s;
	int sindex;
	int circ, leng;
	int *ord;
	int temp;
	int v;
	int ret;
	
	ret = scanf("%d %ld", &N, &K);
	A = (int *)malloc(sizeof(int)*N);
	s = (int *)malloc(sizeof(int)*N);
	ord = (int *)malloc(sizeof(int)*(N+1));
	for (i =0; i < N+1; i++) {
		ord[i] = -1;
	}
	
	for (i =0; i < N; i++) {
		ret =scanf(" %d", &A[i]);
	}

	v = 1;
	sindex=0;
	circ = 0;
	leng = 0;
	while (ord[v] == -1) {
		ord[v] = sindex;
		s[sindex++] = v;
		v = A[v-1];
	}
	circ = sindex - ord[v];
	leng = ord[v];

	if (K < leng) {
		printf("%d\n", s[K]);
	} else {
		K -= leng;
		K %= circ;
		printf("%d\n", s[leng+K]);
	}


	free(A);
	free(s);
	free(ord);
	return EXIT_SUCCESS;
}
