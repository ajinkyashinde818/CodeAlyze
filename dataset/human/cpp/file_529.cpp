#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, n;
    cin >>R >>G >>B >>n;
    int ret = 0;
    for (int r = 0; r <= 3000; r++) {
        for (int g = 0; g <= 3000; g++) {
            if (r*R + g*G <= n && (n - r*R - g*G)%B==0) {
                ret++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
