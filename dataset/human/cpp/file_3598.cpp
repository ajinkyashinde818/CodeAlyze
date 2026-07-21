#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    int cnt = 0;
    for(auto& e : a){
        cin >> e;
        if(e < 0){
            cnt++;
            e *= -1;
        }
    }
    sort(begin(a), end(a));
    if(a[0] == 0) cnt = 0;
    int64_t ans = accumulate(begin(a), end(a), 0LL);
    if(cnt % 2 != 0){
        ans -= 2 * a[0];
    }
    cout << ans << endl;
    return 0;
}
