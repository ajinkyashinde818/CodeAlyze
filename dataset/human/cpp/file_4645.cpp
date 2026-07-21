#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    int ans;
    if (n >= 10)
        ans = r;
    else
        ans = r + 100 * (10 - n);
    cout << ans << endl;
    return 0;
}
