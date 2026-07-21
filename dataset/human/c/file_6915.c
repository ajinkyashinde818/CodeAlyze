#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GYOU_MAX 256
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define s_pri(str) printf("%s\n",str);
#define PRINT(str) printf(#str "\n")
#define v_pri(val) printf("%d\n",val);
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define pi acos(-1.0)
#define sca(x) scanf("%d",&x);

typedef long long int ll;

/*
puts("aa");
//*/


int main(void) {
	

	int N, M;
	sca(N);
	sca(M);

	if (N == M) {
		s_pri("Yes");
	}
	else {
		s_pri("No");
	}



	return 0;
}
