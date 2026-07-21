#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    long a[200000], diff = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        diff += a[i];
    }

    diff -= 2 * a[0];
    //memo: diff = sumDown - sumUp

    long minDiff = abs(diff);
    for (int i = 1; i < n - 1; ++i) {
        diff -= 2 * a[i];
        if (abs(diff) < minDiff) {
            minDiff = abs(diff);
        }
    }

    cout << minDiff << endl;

    return 0;
}
