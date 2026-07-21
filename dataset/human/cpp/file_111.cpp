#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int r, g, b, n;

    cin >> r >> g >> b >> n;

    int cnt = 0;

    
    int ma = max(max(r, g), b);
    int mi = min(min(r, g), b);
    int mm = r + g + b - ma - mi;

    int d = n/ma;
    for (int i = 0; i <= d; i++ ) {
        int a1 = i*ma;
        int r1 = n - a1;
        int d2 = r1/mm;
        for (int j=0; j <= d2; ++j) {
            int r2 = r1 - j*mm;
            if ( r2 % mi == 0 ) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
