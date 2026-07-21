#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long>a;

long long solve();

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;++i)cin >> a[i];
    cout << solve() << endl;
    return 0;
}

long long solve(){
    long long ans = 0,cnt = 0,x = abs(a[0]);
    for(int i = 0;i < n;++i){
        if(a[i] < 0){
            ++cnt;
            a[i] *= -1;
        }
        ans += a[i];
        x = min(a[i],x);
    }
    if(cnt % 2 == 0)return ans;
    return ans - 2 * x;
}
