#include <iostream>
#include <cmath>
using namespace std;

int main () {
    long long n, res = 0, min = 1000000000, num = 0, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp < 0) num++;
        res += abs(temp);
        if (abs(temp) < min) min = abs(temp);
    }
    if (num % 2) cout << res - 2 * min << endl;
    else cout << res << endl;
    return 0;
}
