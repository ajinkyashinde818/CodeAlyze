//
// Created by Chisec Coin on 17/7/15.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <sstream>
#include <map>
const int NIL = -1;
typedef long long ll;
using std::cin;using std::cout;using std::endl;using std::max;using std::min;

ll a[200005], sum1[200005], sum2[200005];

inline ll absll(const ll& i) {
    return i > 0 ? i : -i;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            sum1[i] = a[i];
        } else {
            sum1[i] += sum1[i - 1] + a[i];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            sum2[i] = a[i];
        } else {
            sum2[i] += sum2[i + 1] + a[i];
        }
    }
    int i = 0;
    ll minx = 9223372036854775807;
    while (i != n - 1) {
        minx = min(absll(sum1[i] - sum2[i + 1]), minx);
        i++;
    }
    cout << minx << endl;

    return 0;
}
