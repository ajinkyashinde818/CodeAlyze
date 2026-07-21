#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, t, i, cnt = 0, minValue = 1999999999;
    long long sum = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> t;
        cnt += t < 0;
        minValue = min(minValue, abs(t));
        sum = sum + abs(t);
    }
    if (cnt % 2 == 0) {
        cout << sum;
    }
    else {
        cout << sum - (2 * minValue);
    }

    return 0;
}
