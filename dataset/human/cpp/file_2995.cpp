#include"bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    int mai = 0;
    int pura = 0;
    long long acc = 0;
    long long minn = 1'000'000'000;
    for (int i = 0; i<n; i++){
        if (a[i]<0) mai++;
        else pura++;
        acc += abs(a[i]);
        minn = min(minn,abs(a[i]));
    }
    long long ans;
    if (mai%2!=0) ans=acc-minn*2;
    else ans=acc;
    cout << ans << endl;
}
