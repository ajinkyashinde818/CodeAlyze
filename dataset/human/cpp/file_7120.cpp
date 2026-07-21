#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int N; cin >> N;
    vector<ll> A(N), sum(N); 
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
        if (i == 0) sum.at(i) = A.at(i);
        else sum.at(i) = A.at(i) + sum.at(i-1);
    }
    ll res = -100000;
    for (int i = 0; i < N - 1; i++)
    {
        ll x = sum.at(i), y= sum.at(N-1) - x;
        ll u = max(x, y), v = min(x, y);
        if (res < 0)  res = u - v;
        else if ( res > u - v) res = u- v;
    }
    
    cout << res << endl;
}
