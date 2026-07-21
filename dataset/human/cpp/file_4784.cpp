#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int n, r;
    cin >> n >> r;

    if (n < 10) {
        cout << r + 100 * (10 - n) << endl;
    } else {
        cout << r << endl;
    }

    return 0;
}
