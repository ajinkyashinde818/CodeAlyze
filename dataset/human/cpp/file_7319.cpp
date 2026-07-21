#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long a;
    vector<long long> A;

    cin >> n;

    long long y = 0;
    for (int i=0; i<n; i++) {
        cin >> a;
        A.push_back(a);
        y += a;
    }

    long long x = 0, ans = 9223372036854775807;
    for (int i=0; i<n-1; i++) {
        x += A[i];
        y -= A[i];
        
        ans = min(abs(x-y), ans);
    }

    cout << ans << endl;

    return 0;
}
