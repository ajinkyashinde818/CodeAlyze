#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    size_t n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;
    return 0;
}
