#include <bits/stdc++.h>
using namespace std;

// ------------------------

void solve() {
    int N, R; cin >> N >> R;
    if(N >= 10){
        cout << R << endl;
    }else{
        cout << R + 100*(10 - N) << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
