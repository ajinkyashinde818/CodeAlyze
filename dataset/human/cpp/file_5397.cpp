#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    Int n, r;
    cin >> n >> r;
    if (n < 10) {
        cout << r + 100 * (10 - n) << endl;
    } else {
        cout << r << endl;
    }
    return 0;
}
