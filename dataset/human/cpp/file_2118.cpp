#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int rabs=INT32_MAX;
    int ridx;
    int ncnt=0;
    for(int i = 0; i < n; i++) {
        if(a[i]<0){
            ncnt++;
            a[i]*=-1;
        }
        if(a[i]<rabs){
            rabs=a[i];
            ridx=i;
        }
    }

    ll ans=0;
    for(int i = 0; i < n; i++) {
        ans+=a[i];
    }
    if(ncnt%2==0) cout << ans << "\n";
    else          cout << ans-2*a[ridx] << "\n";

    return 0;
}
