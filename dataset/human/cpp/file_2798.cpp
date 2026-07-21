#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    int cnt = 0;
    for(auto &ai : a){
        cin >> ai;
        if(ai < 0) cnt ++;
        ai = abs(ai);
        ans += ai;
    }
    if(cnt % 2){
        ans -= 2*(*min_element(a.begin(), a.end()));
    }
    cout << ans << endl;

}
