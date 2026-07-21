#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;

ll cumSum[200100];
int main(void) {
    int N;
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll r;
        cin >> r;
        sum += r;
        cumSum[i] = sum;
    }

    ll minDiff = 2100000000;
    for (int i = 0; i < N - 1; i++) {
        ll d = abs(sum - 2 * cumSum[i]);
        minDiff = min(minDiff, d);
    }

    cout << minDiff << endl;
    return 0;
}
