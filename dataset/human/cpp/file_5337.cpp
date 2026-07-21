#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

typedef long long llong;
// -2.1e-9 <= int <= 2.1e9

int main()
{
    int N, R, ans;
    cin >> N >> R;
    if (N >= 10) {
        ans = R;
    }
    else {
        ans = R + 100 * (10 - N);
    }
    cout << ans << endl;
}
