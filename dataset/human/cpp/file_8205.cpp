#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    long long sum = 0;
    vector<long long> a(N);
    for ( int i=0; i<N; i++ ) {
        cin >> a.at(i);
        sum += a.at(i);
    }

    long long ans = LLONG_MAX;
    long long sunuke = 0;
    long long rascal;

    for ( int i=0; i<N-1; i++ ) {
        sunuke += a.at(i);
        rascal = sum - sunuke;
        ans = min(ans, abs(sunuke - rascal));
    }

    cout << ans << endl;
    return 0;
}
