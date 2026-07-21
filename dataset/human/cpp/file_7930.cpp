#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int N;
    int input;
    cin >> N;
    
    vector<int> a;
    for (int i = 0; i<N; i++){
        cin >> input;
        a.push_back(input);
    }
    
    vector<ll> acum(N+1,0);
    for(int i = 0; i<a.size(); i++){
        acum[i+1] = acum[i] + a[i];
    }

    ll ans = 1e18;
    for(int i=1; i< N; i++){
        ll x = acum[i];
        ll y = acum[N]-acum[i];
        ans = min(ans, abs(x-y));
    }
    cout << ans << endl;
    return 0;
}
