#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

ll INF=1000000007;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x[26];

    rep(i,26){
        x[i]=1;
        rep(j,s.size()){
            if(s[j] == 'a' + i) x[i]++;
        }
    }

    ll ans=1;
    rep(i,26){
        ans *= x[i];
      ans %= INF;
    }
    cout << ans-1 << endl;
}
