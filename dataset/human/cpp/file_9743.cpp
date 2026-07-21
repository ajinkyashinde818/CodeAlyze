#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const ll mod = 1000000007;

int main(){

// #ifndef  ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    char ch;
    int f[26] = {0};
    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>ch;
    	f[ch-'a']++;
    }
    ll ans = 1;
    for(int i = 0; i < 26; i++){
    	(ans *= (f[i] + 1)) %= mod;
    }
    cout<<(ans + mod - 1)%mod<<endl;
}
