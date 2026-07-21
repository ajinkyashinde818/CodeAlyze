#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A;
    A.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(A));

    int neg = count_if(A.begin(), A.end(), [](int x) { return x < 0; });
    for_each(A.begin(), A.end(), [](int &x) { x = abs(x); });
    long long ans = accumulate(A.begin(), A.end(), 0LL);
    if (neg & 1) {
        int z = *min_element(A.begin(), A.end());
        ans -= 2LL * z;
    }
    cout << ans << endl;
    return 0;
}
