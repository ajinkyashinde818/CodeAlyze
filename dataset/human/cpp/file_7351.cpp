#include<iostream>
#include<cstdio>

#include<vector>
#include<string>

#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
const ll INF = 1e16+1;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

int N;

int main() {
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<ll> left(N), right(N);
    left[0] = a[0];
    for (int i = 1; i < N; i++) {
        left[i] = left[i-1] + a[i];
    }
    right[N-1] = a[N-1];
    for (int i = N-2; i >= 0; i--) {
        right[i] = right[i+1] + a[i];
    }
    ll res = INF;
    for (int i = 0; i < N-1; i++) {
        chmin(res,abs(right[i+1]-left[i]));
    }
    cout << res << endl;

    



}
