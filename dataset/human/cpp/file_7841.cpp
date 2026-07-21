#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; ll sum=0;
    vector<ll> a,num;
    cin >> n;
    for(int ix=0;ix<n;ix++){
        int tmp; cin >> tmp;
        a.push_back(tmp);
        sum += tmp;
        num.push_back(sum);
    }
    ll ans = 90000000000;
    for(int ix=0;ix<n-1;ix++){
        ll tmp = abs(sum - num.at(ix) - num.at(ix));
        ans = min(tmp,ans);
    }
    cout << ans << endl;
}
