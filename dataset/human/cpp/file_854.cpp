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
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int s = 0;
    for (int i = 0;; i++) {
        int t = n - r * i;
        if (t < 0) break;
        //t個をGとBで
        for (int j = 0;; j++) {
            int u = t - g * j;
            if (u < 0) break;
            if (u % b == 0) s++;
        }
    }

    cout << s << endl;

    return 0;
}
