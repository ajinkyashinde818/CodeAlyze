#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);

    int mnum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<0){
            a[i] *= -1;
            mnum++;
        }
    }
    sort(a.begin(),a.end());

    ll ans = 0;
    if(mnum%2==1) ans -= a[0];
    else ans += a[0];
    for(int i=1;i<n;i++) ans += a[i];
    cout << ans << endl;

}
