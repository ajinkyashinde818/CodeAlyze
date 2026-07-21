//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

ll t[3], n;

ll ways(int pos, ll rem){
	if(pos==2) return rem%t[pos]==0;
	ll ret=0;
	for(ll i=0; i*t[pos]<=rem; i++){
		ret+=ways(pos+1, rem-i*t[pos]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FOR(i, 0, 2) cin>>t[i];
	cin>>n;
	cout<<ways(0, n)<<ent;
	return 0;
}
