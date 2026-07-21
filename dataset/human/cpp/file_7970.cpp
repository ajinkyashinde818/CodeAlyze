#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;

long long n;
long long a[200010];
long long t1[200010];
long long t2[200010];

int main() {
    cin >> n;
    t2[0] = 0;
    imfor(i, n) {
        cin >> a[i];
        t2[0] += a[i];
    }
    t2[0] -= a[0];
    imfor(i, n) {
        if (i == 0) {
            t1[i] = a[i];
            continue;
        }
        t1[i] = t1[i - 1] + a[i];
        t2[i] = t2[i - 1] - a[i];
    }
    long long min = abs(t1[0] - t2[0]);
    long long mini = 0;
    for (int i = 0; i < n - 1; i++) {
        if (abs(t1[i] - t2[i]) < min) {
            min = abs(t1[i] - t2[i]);
            mini = i;
        }
    }
    cout << min << endl;
}
