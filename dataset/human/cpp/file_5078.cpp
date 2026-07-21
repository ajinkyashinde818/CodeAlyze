#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <map>
#include <unordered_map>
#include <tuple>
 
using namespace std;
 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define umap unordered_map
#define uset unordered_set
#define cina(s, n, a) for(int i = s; i < n; i++) cin >> a[i]
#define couta(s, n, a) for(int i = s; i < n; i++) cout << a[i] << ' '
#define copy(s, n, a, b) for(int i = s; i < n; i++) b[i] = a[i]
#define yesno(ok) cout << (ok ? "YES\n" : "NO\n")
#define mod(a, b) (b + (a % b)) % b
#define MOD (int)1e9 + 7
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

void add_self (int& a, int b){ a += b; if (a >= MOD) a -= MOD; }
//-------------------------------------------------------------------------------------------------------//

void solve(){
    int n, r;
    cin >> n >> r;
    if(n >= 10) cout << r;
    else{
        cout << r + 100 * (10 - n);
    }
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q = 1;
    //cin >> q;
    for(int i = 1; i <= q; i++){
        solve();
    }
}
