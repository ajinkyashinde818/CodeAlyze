// by DenyTianly
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define iScf(n) scanf("%d", &n)
#define dug() printf("ok!\n")
#define iNxtL() puts("")
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define nrep(i, val, n) for(int i = val; i < n; i++)
#define ipq priority_queue
typedef long long LL;
typedef unsigned long long ULL;

const int inf = 1 << 26;
const LL INF = 1LL << 60;

inline void quick_IO() { ios::sync_with_stdio(false); cout.tie(0); cin.tie(0); }
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();

	for(; ch < '0' || ch > '9'; ch = getchar())
		if(ch == '-') f = -f;

	for(; ch >= '0' && ch <= '9'; ch = getchar())
		x = x*10+ch-'0';

	return x*f;
}

// Don't hack me, please ~
// #define _Isopen_File_
// #define _Is_Close_STD_

char a[55][55], b[55][55];
int n, m;

bool cont(int x1, int y1, int x2, int y2) {
	int ci = 0, cj = 0;
	for ( int i = x1; i <= x2; i ++, ci ++) {
		for( int j = y1; j <= y2; j ++, cj++ ) {
			if(a[i][j] != b[ci][cj]) return false;
		}
		cj = 0;
	}
	return true;
}

int main(){

#ifdef _Isopen_File_
	freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
#endif

#ifdef _Is_Close_STD_
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif

	// freopen("B.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < n; i ++ ) scanf("%s", a[i]);
	for ( int j = 0; j < m; j ++ ) scanf("%s", b[j]);

	for ( int i = 0; i <= n-m; i ++ ) {
		for ( int j = 0; j <= n-m; j ++ ) {
			if(cont(i, j, i+m-1, j+m-1)){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");

	return 0;
}
