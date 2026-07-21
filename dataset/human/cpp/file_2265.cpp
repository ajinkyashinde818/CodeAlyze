// -*- mode: cpp; coding=utf-8-unix; -*-
// vim: filetype=cpp fileencoding=utf-8 fileformat=unix
#include <iostream>
#include <iomanip>
#include <math.h>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <string.h>
// #include <limits.h>

#define FOR(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define FORUL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define FORULE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#if defined(_MSC_VER) || __cplusplus > 199711L
#define AUTOVAR(newvar,v) auto newvar = (v)
#else
#define AUTOVAR(newvar,v) __typeof(newvar) r = (v)
#endif
#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define MEMSET(m,v) memset(m,v,sizeof(m))

typedef long long				 ll;
typedef unsigned long long		ull;

#define INTMAX  99999999

#define DEBUG 1

#if DEBUG
#define DOUT cout<<"["<<__LINE__<<"]:"
#else
#define DOUT 0 && cout
#endif

using namespace std;

#define MAXN (1000*100)
int N;
int A[MAXN];
ll dp[MAXN][2];

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);

	cin >> N;
	for(int n=0; n<N; n++) {
		cin >> A[n];
	}
	// if (A[0]>=0) {
		dp[0][0] = A[0];
		dp[0][1] = -A[0];
	// }
	// else {
	// 	dp[0][0] = -A[0];
	// 	dp[0][1] = A[0];
	// }
	for(int n=0; n<N-1; n++) {
		dp[n+1][0] = max(
				dp[n][0]+A[n+1], // ひとつ前はひっくり返してなくて、自分もひっくり返してない。(A[n])
				dp[n][1]-A[n+1]);  // ひとつ前がひっくり返されて、自分はひっくり返してない
		dp[n+1][1] = max(
				dp[n][0]-A[n+1], // ひとつ前はひっくり返してなくて、自分はひっくり返した
				dp[n][1]+A[n+1]
				);
		// cout << "dp["<<n+1<<"][0]="<<dp[n+1][0]<<endl;
		// cout << "dp["<<n+1<<"][1]="<<dp[n+1][1]<<endl;
	}


	cout << max(dp[N-2][0]+A[N-1],dp[N-2][1]-A[N-1]) << endl;


	return 0;
}
