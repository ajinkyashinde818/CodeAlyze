#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    int ct=0;
    int min_n=abs(a[0]);
    for(int i=0;i<n;++i){
        if(a[i]<0) ct++;
        int res = abs(a[i]);
        if(res<min_n) min_n=res;
    }
    long long ans = 0;
    for(int i=0;i<n;++i){
       ans += abs(a[i]);
    }
    if(ct%2==1){
        ans -= 2*min_n;
    }
    cout << ans << endl;
    return 0;
}
