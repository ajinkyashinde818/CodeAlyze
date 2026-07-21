#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R, G, B, N;

    cin >> R >> G >> B >> N;

    int res = 0;

    for (int r = 0; r <= N; r += R) {
        for (int g = 0; r + g <= N; g += G) {
            int b = N - r - g;
            if (b % B == 0) {
                res++;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
