#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<long long> le(n-1), ri(n-1);
    long long sle = 0, sri = 0;
    for (int i=0; i<n-1; ++i) {
        sle += a[i];
        le[i] = sle;
    }
    for (int i=n-1; i>0; --i) {
        sri += a[i];
        ri[i-1] = sri;
    }
    long long m = 1e18;
    for (int i=0; i<n-1; ++i) {
        m = min(m, abs(le[i] - ri[i]));
    }
    cout << m << endl;
}
