#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll all=0;
    vector<ll> tot(n);
    for(int i=0; i<n; i++){
        cin >> tot.at(i);
        all += tot.at(i);
        if(i>=1) tot.at(i)+=tot.at(i-1);
    }
    ll ans=pow(10,18);
    for(int i=0; i<n-1; i++){
        ll dif = abs(tot.at(i)-(all-tot.at(i)));
        ans = min(ans, dif);
    }
    cout << ans << endl;
}
