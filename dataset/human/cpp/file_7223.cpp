#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin  >> n;
    int a[n];
    ll sum = 0,ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }
    ll k = 0;
    for(int i = 0; i < n-1; i++){
        k += a[i];
        ans = min(ans,abs(sum-2 * k));
    }
    cout << ans << endl;
}
