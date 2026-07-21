#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
int main() {
   int N;
   cin >> N;
   vector<ll> a(N);

   for (int i = 0; i < N; i++)
   {
       cin >> a[i];
   }
   
   ll sum = 0;

   for (int i = 0; i < N; i++)
   {
       sum += a[i];
   }
   ll ans = 10000000000;
   ll s = 0;
   for (int i = 0; i < N - 1; i++)
   {
       sum -= a[i];
       s += a[i];
        if (ans > abs(sum - s))
    {
        ans = abs(sum - s);
    }
       
   }
   

    cout << ans << endl;

    return 0;

}
