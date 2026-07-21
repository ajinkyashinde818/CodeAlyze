#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    int minus = 0;
    ll sum = 0;
    ll abs_min = 10e9+1;
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
        ll ab = abs(A.at(i));
        sum += ab;
        abs_min = min(ab, abs_min);
        if (A.at(i) < 0) minus++;
    }
    if (minus % 2 == 0) cout << sum << endl;
    else cout << sum - abs_min*2  << endl;
}
