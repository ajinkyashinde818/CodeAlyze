#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r;

    cin >> n >> r;

    printf("%d\n", n < 10 ? r + 100 * (10 - n) : r);

    return 0;
}
