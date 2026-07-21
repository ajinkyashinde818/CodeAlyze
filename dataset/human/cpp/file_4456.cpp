#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const	int N = 100005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e15;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#else
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int fa[N * 5], sz[N * 5];
int n, a[N], b[N], pos[N], tot, X, seq;
map<int, int> A, B, C;

int get(int x){
	if(fa[x] == x) return fa[x];
	return fa[x] = get(fa[x]);
}

int Cnt(int x){
	if(B.find(x) == B.end()) return 0;
	return B[x];
}

int main(){

	scanf("%d", &n);
	REP(i, 1, n){
		scanf("%d", a + i);
		X ^= a[i];
		A[a[i]] ++;
		if(!C[a[i]]) C[a[i]] = ++seq;
	}
	REP(i, 1, n){
		scanf("%d", b + i);
		B[b[i]] ++;
		if(!C[b[i]]) C[b[i]] = ++seq;
	}

	if(!C[X]) C[X] = ++seq;

	int flag = 1;
	REP(i, 1, n) if(a[i] != b[i]) flag = 0;
	if(flag){
		cout << 0 << endl;
		return 0;
	}

	A[X] ++;
	int ok = -1;
	for(auto x : A) if(Cnt(x.fi) + 1 == x.se){
		ok = x.fi;
		break;
	}

	if(ok == -1){
		cout << -1 << endl;
		return 0;
	}


	int oke = 1;
	for(auto x : A) if(x.fi != ok && Cnt(x.fi) != x.se){
		oke = -1;
		break;
	}

	if(oke == -1){
		cout << -1 << endl;
		return 0;
	}

	REP(i, 1, seq) fa[i] = i;
	REP(i, 1, n) if(a[i] != b[i]){
		int u = C[a[i]], v = C[b[i]];
		fa[get(u)] = get(v);
		++ tot;
	}

	REP(i, 1, seq) sz[get(i)] ++;

	REP(i, 1, seq) if(get(i) == i && sz[i] != 1) tot ++;
	tot --;
	if(A[X] == 1 && ok == X) tot ++;


	printf("%d\n", tot);


#ifdef LOCAL
	cerr << endl << endl << "Time Spec = " << clock() / 1000. << "ms" << endl;
#endif
	return 0;
}
