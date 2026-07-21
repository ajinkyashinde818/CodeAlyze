#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n, r;

int main() {
    cin >> n >> r;

    if (n >= 10) {
        cout << r << endl;
    }
    else {
        cout << r + (100 * (10 - n)) << endl;
    }

    return 0;
}
