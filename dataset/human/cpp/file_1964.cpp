#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    int small = 1e9;
    bool odd = 0;
    while (n--) {
        int tmp;
        cin >> tmp;
        sum += abs(tmp);
        small = min(abs(tmp), small);
        if (tmp < 0)
            odd = !odd;
    }
    if (odd) {
        sum -= 2 * small;
    }
    cout << sum;
}
