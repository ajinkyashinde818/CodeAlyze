#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <map>

using namespace std;
using lli = long long int;
using ll = long long;

int main() {
    lli N, R;
    cin >> N >> R;
    if (N > 9) {
        cout << R << endl;
    } else {
        cout << R + (10 - N) * 100;
    }
}
