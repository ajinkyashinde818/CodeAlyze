#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, R;
    cin >> N >> R;

    if (N >= 10) {
        cout << R << "\n";
    } else {
        cout << R + 100 * (10 - N) << "\n";
    }

    return 0;
}
