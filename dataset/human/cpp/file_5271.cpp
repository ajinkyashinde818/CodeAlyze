#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e17;
const ll MOD = 1e9+7;

int main() {
    // input, ready
    int N,R;
    cin >> N >> R;

    if (N>=10) cout << R << endl;
    else cout << R + 100 * (10-N) << endl;

    return 0;
}
