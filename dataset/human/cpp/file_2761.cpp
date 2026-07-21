#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;
using namespace std;
#define int long long int

inline void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int neg = 0;
    for (int i = 0; i < N; i++) {
        int _a; cin >> _a;
        if (_a < 0) neg++;
        A[i] = _a;
    }

    int mini = -1;
    if (neg % 2 != 0) {
        int minA = 0;
        for (int i = 0; i < N; i++) {
            if (mini == -1 || minA * minA > A[i] * A[i]) {
                minA = A[i];
                mini = i;
            }
        }
    }

    int sumB = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            A[i] *= -1;
        }
        if (mini == i && A[i] > 0) {
            A[i] *= -1;
        }
        sumB += A[i];
    }
    cout << sumB << endl;
    return 0;
}
