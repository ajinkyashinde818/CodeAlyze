#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
int main() {
    int N, R; cin >> N >> R;
    if (N >= 10) {
        cout << R << endl;
    } else {
        cout << R + 100 * (10 - N) << endl;
    }
    return 0;
}
