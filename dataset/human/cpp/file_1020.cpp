#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int r = 0; r * R <= N; r++) {
        for (int g = 0; r * R + g * G <= N; g++) {
            if ((N - r * R - g * G) % B == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
