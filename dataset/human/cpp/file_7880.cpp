#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int ans=0,sum=0,acm=0;
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
        sum += a[i];
    }

    sum -= a[0];
    acm += a[0];
    ans = abs(sum-acm);

    for(int i=1;i<N-1;i++){
        sum -= a[i];
        acm += a[i];
        ans = min(abs(sum-acm),ans);
    }

    cout << ans << endl;
}
