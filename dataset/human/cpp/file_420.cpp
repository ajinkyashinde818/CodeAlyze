#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
using ll=long long int;

int main() {
    int R, G, B;
    cin >> R >> G >> B;
    int n;
    cin >> n;

    int ans = 0;
    for (int r = 0; R*r <= n; ++r) {
        for (int g = 0; R*r+G*g <= n; ++g) {
            if ((n - R*r - G*g) % B == 0) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
