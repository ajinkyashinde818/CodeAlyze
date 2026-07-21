#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<long long> a(n, 0);
    long long lsum = 0;
    long long rsum = 0;

    for(int i = 0; i < n; ++i) {
        cin >> a.at(i);
        rsum += a.at(i);
    }

    long long min = 1e16+7;
    for(int i = 0; i < n-1; ++i) {
        lsum += a.at(i);
        rsum -= a.at(i);
        if(abs(lsum-rsum) < min) {
            min = abs(lsum-rsum);
        }
    }

    cout << min << endl;
}
