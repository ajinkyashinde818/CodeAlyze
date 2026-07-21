#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n,i;
    cin >> n;
    vector<int> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<ll> sum(n);
    sum.at(0) = a.at(0);
    for(i = 1;i < n;++i){
        sum.at(i) = sum.at(i-1) + a.at(i);
    }
    ll alsum = sum.at(n-1);
    ll ans = abs(alsum - 2*sum.at(0));
    for(i = 1;i < n-1;++i){
        if(ans > abs(alsum - 2*sum.at(i))){
            ans = abs(alsum - 2*sum.at(i));
        }
    }
    cout << ans << endl;
    return 0;
}
