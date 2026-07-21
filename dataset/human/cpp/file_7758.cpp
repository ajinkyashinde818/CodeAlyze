#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    vector<ll> sum_a(N);
    sum_a[0] = a[0];
    for(int i = 1; i < N; i++){
        sum_a[i] = sum_a[i-1] + a[i];
    }

    ll ans = INF;
    for(int i = 0; i < N-1; i++){
        chmin(ans, abs(sum_a[i] - (sum_a[N-1]-sum_a[i])  ));
    }

    cout << ans << endl;


    return 0;
}
