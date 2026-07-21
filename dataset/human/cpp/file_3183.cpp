#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nc = 0, nm = 1e9+1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            nc++;
        }
        a = abs(a);
        ans += a;
        nm = min(nm, a);
    }

    cout << (nc % 2 == 0 ? ans : ans - nm * 2) << endl;

    return 0;
}
