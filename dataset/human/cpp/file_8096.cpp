#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <numeric>

using namespace std;

using ll = long long;


int main()
{
    ll N;
    cin >> N;

    vector<ll> A;
    for (auto i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    ll arai = accumulate(A.begin(), A.end(), 0LL);
    ll sunuke = A[0];
    arai -= A[0];
    ll ans = abs(sunuke - arai);
    // cout << "sunuke: " << sunuke << ", arai: " << arai << endl;
    for (auto it = A.begin() + 1; it != A.end() - 1; ++it) {
        sunuke += *it;
        arai -= *it;
        ans = min(ans, abs(sunuke - arai));
        // cout << "sunuke: " << sunuke << ", arai: " << arai << endl;
    }
    cout << ans << endl;
}
