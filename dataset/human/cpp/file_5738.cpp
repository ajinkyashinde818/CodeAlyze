#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
#include <complex>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define deb(a) cerr<< #a << "= " << (a)<<"\n";

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef complex<double> base;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class T> ostream& operator<<(ostream& stream, const vector<T> v){ stream << "[ "; for (int i=0; i<(int)v.size(); i++) stream << v[i] << " "; stream << "]"; return stream; }
ll fpow(ll x, ll p, ll m){ll r=1; for (;p;p>>=1){ if (p&1) r=r*x%m; x=x*x%m; } return r;}
ll inv(ll a, ll b){ return a<2 ? a : ((a-inv(b%a,a))*b+1)/a %b; }
int gcd(int a, int b){ if (!b) return a; return gcd(b,a%b);}
ll gcd(ll a, ll b){ if (!b) return a; return gcd(b,a%b);}

ll N,t[120000][2],T; bool f[120000];
ll L;

string s; ll root=0;

ll val=0;

void ins(ll &nod, ll p, string &s){
	if (nod==0)
		nod=++T;
	
	if (p==s.length()){
		f[nod]=1;
		return;
	}
	
	ins(t[nod][s[p]-'0'],p+1,s);
}

void addv(ll d){
	ll b=(d&-d);
	
	val^=b;
}

void dfs(ll nod, ll d){
	if (f[nod]) return;
	
	int i;
	for (i=0; i<2; i++)
		if (t[nod][i]==0){
			ll id=L-d-1;
			addv(id+1);
		}
		else dfs(t[nod][i],d+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;
	
	int i;
	for (i=1; i<=N; i++){
		cin >> s;
		ins(root,0,s);
	}
	
	dfs(root,0); bool ans=0;
	if (val!=0) ans=1;
	
		
	cout << (ans ? "Alice\n" : "Bob\n");
	return 0;
}
