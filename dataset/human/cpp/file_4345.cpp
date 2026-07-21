#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

const int INF = 2e9;
const int MOD = 1e9+7;
const int MAX = 1e5+10;
const lint LNF = 2e18;

int n, A[MAX], B[MAX];

bool check(){
	int C[MAX], D[MAX];
	for(int i=0; i<=n; i++) C[i]=A[i], D[i]=B[i];
	sort(C, C+n+1); sort(D, D+n+1);
	for(int i=0; i<=n; i++)
		if(C[i]!=D[i]) return false;
	return true;
}

int m=0;

int f(int x){
	static map<int, int> mem;
	if(mem.find(x)!=mem.end()) return mem[x];
	return mem[x]=++m;
}

int U[MAX], sz[MAX];
int find(int x){
	return x==U[x] ? x : U[x]=find(U[x]);
}
void unite(int x, int y){
	x = find(x), y = find(y);
	if(x!=y) U[y] = x, sz[x]+=sz[y];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i], A[0]^=A[i];
	for(int i=1; i<=n; i++) cin>>B[i], B[0]^=B[i];

	if(!check()){ cout<<"-1\n"; return 0; }


	for(int i=0; i<=n; i++){
		A[i] = f(A[i]); B[i] = f(B[i]);
	}

	for(int i=1; i<=m; i++) U[i] = i, sz[i] = 1;

	int ans=n+1;
	for(int i=0; i<=n; i++)
		if(A[i]!=B[i]){
			unite(A[i], B[i]);
		} else {
			ans--;
		}
	
	for(int i=1; i<=m; i++){
		if(i!=find(i) || sz[i]==1) continue;
		if(find(i)!=find(A[0])) ans++;
		if(find(i)==find(A[0]) && A[0]!=B[0]) ans--;
	}

	cout<<ans<<'\n';

	return 0;
}
