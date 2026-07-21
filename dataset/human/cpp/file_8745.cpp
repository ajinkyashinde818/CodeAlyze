#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n,m; cin>>n>>m;
	vvi vec(n,vi(n));
	vvi vec2(m,vi(m));
	rep(i,0,n){
		string s;
		cin>>s;
		rep(j,0,n){
			vec[i][j]=s[j];
		}
	}
	rep(i,0,m){
		string s;
		cin>>s;
		rep(j,0,m){
			vec2[i][j]=s[j];
		}
	}
	rep(i,0,n-m+1){
		rep(j,0,n-m+1){
			bool ok=true;
			rep(k,0,m){
				rep(l,0,m){
					if(vec[i+k][j+l]!=vec2[k][l]) ok=false;
				}
			}
			if(ok){
				cout<<"Yes";
				return 0;
			}
		}
	}	
	cout<<"No";		
	return 0;
}
