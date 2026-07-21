#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    int n, r;
    cin >> n >> r;
    if (n >= 10) {
        cout << r;
    } else {
        cout << (r + 100 * (10 - n));
    }
}
