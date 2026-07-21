#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
	int n, m;
	cin >> n >> m;
	VI used(n+1), ans, e(m);

	REP(i,m) cin >> e[i];

	FORR(i,m-1,0){
		int x = e[i];
		if (!used[x]){
			ans.push_back(x);
			used[x] = 1;
		}
	}

	REP(i,ans.size()) cout << ans[i] << endl;
	FOR(i,1,n) if(!used[i]) cout << i << endl;

    return 0;
}
