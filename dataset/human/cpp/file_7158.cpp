#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
	#define eprintf(...) printf(__VA_ARGS__)
#else 
	#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))
//#define int long long int //dont forget to change int to signed

int main() {
	int N;
	scanf("%d", &N);
	lli a[2*1000*100+9];
	SET_ZERO(a);
	for (int i = 1; i <= N; i++) {
		lli lld;
		scanf("%lld", &lld);
		a[i] = a[i-1] + lld;
	}

	lli min = 1001001001001001;
	for (int i = 1; i <= N-1; i++) {
		lli x = a[i], y = a[N] - a[i];
		chmin<lli>(min, x-y>0?x-y:y-x);
	}
	printf("%lld\n", min);
	return 0;
}
