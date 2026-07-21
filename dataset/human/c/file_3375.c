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


	char S[100001];
	scanf("%s", S);

	while (strlen(S) > 0) {
		if (strcmp(&S[strlen(S) - 7], "dreamer") == 0) {
			S[strlen(S) - 7] = 0;
		}
		else if (strcmp(&S[strlen(S) - 5], "dream") == 0) {
			S[strlen(S) - 5] = 0;
		}
		else if (strcmp(&S[strlen(S) - 6], "eraser") == 0) {
			S[strlen(S) - 6] = 0;
		}
		else if (strcmp(&S[strlen(S) - 5], "erase") == 0) {
			S[strlen(S) - 5] = 0;
		}
		else {
			s_pri("NO");
			return 0;
		}
		
	}
	
		if (S[0] == 0) {
			s_pri("YES");
		}
		else {
			s_pri("NO");
		}
		

	return 0;
}
