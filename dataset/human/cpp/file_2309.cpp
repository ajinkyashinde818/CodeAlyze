#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> v(n);
    int64_t vMin = 1000000000000;
    int64_t ans = 0;
    int numOfMinus = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vMin = min(vMin, abs(v[i]));
        if (v[i] < 0) numOfMinus++;
        ans += abs(v[i]);
    }
    if (numOfMinus % 2 == 0) {
        cout << ans << endl;
    } else {
        cout << ans - 2 * vMin << endl;
    }
}
