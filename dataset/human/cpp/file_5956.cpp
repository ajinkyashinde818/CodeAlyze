#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
typedef long long lint;

int main() {
    int N;
    lint C;
    cin >> N >> C;
    vector<lint> xs(N), vs(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i] >> vs[i];
    }
    vector<lint> right(N+1), left(N+1), right2(N+1), left2(N+1);
    // 時計回り(right)
    {
        lint sum = 0;
        for (int i = 0; i < N; i++) {
            sum += vs[i];
            right[i+1] = sum - xs[i];
            right2[i+1] = sum - 2 * xs[i];
        }
    }
    // 反時計回り
    {
        lint sum = 0;
        for (int i = N-1; i >= 0; i--) {
            sum += vs[i];
            left[i+1] = sum - (C - xs[i]);
            left2[i+1] = sum - 2 * (C - xs[i]);
        }
    }
    lint ans = 0;
    // 時計回り -> 戻る -> 反時計回り
    {
        lint maxi = 0;
        for (int i = 0; i <= N; i++) {
            ans = max(ans, maxi + left[i]);
            maxi = max(maxi, right2[i]);
        }
    }
    // 反時計回り -> 戻る -> 時計回り
    {
        lint maxi = 0;
        for (int i = N; i >= 0; i--) {
            ans = max(ans, maxi + right[i]);
            maxi = max(maxi, left2[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
