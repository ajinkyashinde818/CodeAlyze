#include<algorithm>
#include<chrono>
#include<climits>
#include<numeric>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
 
#define rep(i, a, b) for(auto i = (a); i < (b); i++)
#define rrep(i, a, b) for(auto i = (a); i > (b); i--)
#define all(v) (v).begin(), (v).end()
#define print(v) {for(auto x : v) cout << x << ' '; cout << endl;}
#define printn(v, n) {for(int _i = 0; _i < n; _i++) cout << *(v + _i) << ' '; cout << endl;}
 
typedef unsigned long long ull;
typedef long long ll;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
 
const int MAXN = 2000 + 20;
const long long mod = 1e9 + 7;
int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    if(s[0] == 'W') {
    	cout << 0 << endl;
    	return 0;
    }

    long long res = 1, cur = 1, op = 1;
    for(int i = 1; i < 2 * n; i++) {
    	if(s[i] == s[i - 1])
    		op = 1 - op;
    	if(op)
    		cur++;
    	else {
    		res = (res * cur) % mod;
    		cur--;
    	}
    	//cout << i << ' '  << cur << ' ' << res << endl;
    }
    if(cur != 0)
    	cout << 0 << endl;
    else {
	    for(int i = 1; i <= n; i++)
	    	res = (res * i) % mod;
	    //res = (res * 2) % mod;
	    cout << res << endl;
	}
    return 0;
}
