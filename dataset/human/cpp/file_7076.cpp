#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    for(auto itr = a.begin(); itr != a.end(); itr++){
		cout << *itr << " ";
	}
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){
	cout << "debug: " << a << " " << b << "\n";
}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << "debug: " << a << " " << b << " " << c << "\n";
}
void mark() {cout << "#" << "\n";}
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int n;

int main(){
	cin >> n;
	vl a(n), b(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	reverse(all(b));
	int p = -1;
	int l = 0, r = n;
	rep(i,n){
		if(a[i] == b[i]){
			if(p == -1){
				p = a[i];
				l = i;
			}
		}else{
			if(p != -1){
				if(r == n) r = i;
			}
		}
	}
	if(p == -1){
		cout << "Yes" << "\n";
		print(b);
		return 0;
	}
	int id = 0;
	for(int i=l; i<r; i++){
		while(id < n && (a[id] == p || b[id] == p)) id++;
		if(id == n){
			rep(j,n){
				if(a[j] == b[j]){
					cout << "No" << "\n";
					return 0;
				}
			}
			cout << "Yes" << "\n";
			print(b);
			return 0;
		}
		swap(b[id], b[i]);
		id++;
	}
	cout << "Yes" << "\n";
	print(b);
}
