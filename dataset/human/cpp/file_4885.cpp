#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r;
    if (n < 10) {
        cout << r + 100 * (10 - n) << endl;
    } else {
        cout << r << endl;
    }

    return 0;
}
