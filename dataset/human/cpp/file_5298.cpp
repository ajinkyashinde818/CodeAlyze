#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 5;
const int MOD = int(1e9) + 7;
const int inf = int(2e9);



int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int N,R;
    cin >> N >> R;
    if (N >= 10) cout << R;
    else cout << R + 100*(10-N);
    return 0;
}
