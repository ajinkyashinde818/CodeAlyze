#include <bits/stdc++.h>
using namespace std;

int n;
int a[212345];
long long S,sum1,sum2;

int main() {
 //   freopen("test.txt","r",stdin);
    cin >> n ;
    for (int i =1 ; i <= n ; i++) cin >> a[i] , S += a[i];
    long long ans = 10e10;
    for (int i =1 ; i < n ; i++) {
        sum1 += a[i];
        sum2 = S - sum1;
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans;
}
