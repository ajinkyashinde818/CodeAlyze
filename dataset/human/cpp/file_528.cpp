#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int i = 0; i <= N; i += R) {
        for (int j = i; j <= N; j += G) {
            if ((N - j) % B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
