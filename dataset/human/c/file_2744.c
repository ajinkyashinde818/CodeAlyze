#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define ps(x) printf("%s\n", x)
 
#define INF 100000000000
#define MOD 1000000007
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
 
int main() {
	long K, S;
	long X, Y, Z;
	long i, j;
	long tmp;
	long ans = 0;
	long min_i, max_i;
	
	sl(K); sl(S);
	
	for(X=0;X<=K;X++) {
		for(Y=0;Y<=K;Y++) {
			if(0 <= S-X-Y && S-X-Y <= K) {
				ans++;
			}
		}
	}
	
	pl(ans);
	
	return 0;
}
