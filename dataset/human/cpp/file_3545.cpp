/**
 * @Author:      G_bg
 * @DateTime:    2019-04-27 21:25:33
 * @Description: 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = 3.1415926535898;
const double E = 2.718281828459;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const int maxn=1e5+10;
int a[maxn];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    int sum_ = 0;
    int mi = INF;
    LL ans = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] < 0) sum_++;
        ans += abs(a[i])*1LL;
        mi = min(mi,abs(a[i]));
    }
    if(sum_ & 1) ans -= 2*mi;
    cout << ans << endl;
    //system("pause");
    return 0;
}
