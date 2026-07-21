#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> front(N);
    vector<ll> back(N);
    ll sum_front = 0;
    for (int i = 0; i < N; i++) {
      ll d;
      cin >> d;
      a[i] = d;
      sum_front += d;
      front[i] = sum_front;
    }
    ll sum_back = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
      sum_back += a[i];
      back[i] = sum_back;
    }
    ll out = INF;
    for (int i = 0; i< N-1; i++){
      out = min(out, abs(front[i] - back[i + 1]));
    }
    cout << out << endl;
    return 0;
}
