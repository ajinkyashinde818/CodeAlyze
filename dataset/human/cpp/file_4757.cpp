#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, R;
    cin >> N >> R;
    if (N >= 10) {
        cout << R << endl;
    } else {
        cout << R + 1000 - (100 * N) << endl;
    }
    return 0;
}
