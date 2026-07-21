// to format a document: ctrl + K -> ctrl + D

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int i = 0; i <= N; i += R) {
        for (int j = 0; j <= N - i; j += G) {
            if ((N - i - j) % B == 0) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
