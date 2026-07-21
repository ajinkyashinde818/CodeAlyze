#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n,m;
	cin >> n >> m;
	vector<string> a(n),b(m);
	REP(i,n) cin >> a[i];
	REP(i,m) cin >> b[i];
	
	for(int i=0; i<n-m+1; i++){
		for(int j=0; j<n-m+1; j++){
			bool ok = true;
			for(int x=0; x<m; x++){
				for(int y=0; y<m; y++){
					if(a[i+x][j+y]!=b[x][y]){
						ok = false;
					}
				}
			}
			if(ok){
				cout << "Yes\n";
				return 0;
			}
		}
	}
	
	cout << "No\n";
	
	return 0;
}
