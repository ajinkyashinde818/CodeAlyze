#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {
    int n, cont = 0;
    lli a[100000], small = 1e10, sum = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        small = min(small, abs(a[i]));
        sum += abs(a[i]);
        if (a[i] < 0) cont++;
    }

    if (cont%2) sum -= small*2;

    cout << sum << endl;

    return 0;
}
