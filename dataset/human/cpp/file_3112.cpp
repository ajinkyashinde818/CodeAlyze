#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<long long> a(n);
    long long ans=0, cnt=0, mi=1000000010;
    for(int i=0;i<n;++i){
        cin >> a[i];
        if(a[i]<=0) ++cnt;
        if(mi > abs(a[i])) mi = abs(a[i]);
    }
    if(cnt%2==0){
        for(int i=0;i<n;++i) ans += abs(a[i]);
    }else{
        for(int i=0;i<n;++i) ans += abs(a[i]);
        ans -= abs(mi)*2;
    }
    cout << ans << endl;
}
