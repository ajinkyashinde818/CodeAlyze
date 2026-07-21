#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int64_t> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    partial_sum(a.begin(), a.end(), a.begin());

    int64_t ans = INT64_MAX;
    for(int i=0; i<N-1; i++) {
        ans = min(ans, abs(a[N-1] - 2*a[i]));
    }

    cout << ans << endl;
    return 0;
}
