#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int minus = 0;
    long long a[n];
    long long min = LLONG_MAX;
    int p = -1;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) minus++;
        if (abs(a[i]) < min) {
            min = abs(a[i]);
            p = i;
        }
    }
    long long x = 0;
    if (minus % 2 == 0) {
        for (int i = 0; i < n; i++) {
            x += abs(a[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i == p) {
                if (a[i] > 0) {
                    x -= a[i];
                } else {
                    x += a[i];
                }
            }
            else {
                x += abs(a[i]);
            }
        }
    }
    cout << x << endl;
}
