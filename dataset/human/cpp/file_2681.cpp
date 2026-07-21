#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = (int)1e9 + 7;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    int cnt = 0, haszero = 0;
    long long sum = 0;
    int mi = INF;
    for (int ai: a) {
        cnt += ai < 0;
        haszero += ai == 0;
        sum += abs(ai);
        mi = min(mi, abs(ai));
    }
    if (cnt % 2 == 0 || haszero) cout << sum << endl;
    else cout << sum - mi * 2 << endl;
    return 0;
}
