#include<stdio.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<string>
#include<iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
#include<functional>
#include<list>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 100005;
const int MM = 1000000007;

int D[MX], E[MX];

struct UF{
	map<int,int> L;
	int find(int x){
		return L.find(x) == L.end()? x : L[x] = find(L[x]);
	}
	int merge(int a, int b){
		a = find(a), b = find(b);
		return a == b ? 0 : (L[a] = b, 1);
	}
} uf;

int main()
{
	map<int, int> X, Y;
	int N, g = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", D+i), g ^= D[i]; D[N+1] = g;
	g = 0;
	for(int i = 1; i <= N; i++) scanf("%d", E+i), g ^= E[i]; E[N+1] = g;
	N++;

	for(int i = 1; i <= N; i++) X[D[i]] += 1;
	for(int i = 1; i <= N; i++) Y[E[i]] += 1;

	for(auto c : X){
		if( X[c.first] != Y[c.first] ) return !printf("-1\n");
	}

	set<int> L;
	int ans = 0;
	for(int i = 1; i <= N; i++) if( D[i] != E[i] ) ans++, L.insert(D[i]);
	if( L.size() == 0 ) return !printf("0\n");
	ans += L.size();
	for(int i = 1; i <= N; i++){
		ans -= uf.merge(D[i], E[i]);
	}
	if( D[N] != E[N] ) ans-=2;
	else if( D[N] == E[N] && L.find(D[N]) != L.end() ) ans--;
	printf("%d\n", ans);
}
