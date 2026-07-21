#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n, r;
    int ans;
    cin >> n >> r;
    if (n >= 10) {
        ans = r;
    }
    else {
        ans = r + 100 * (10 - n);
    }
    cout << ans << endl;
}
