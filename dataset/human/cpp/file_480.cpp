#include <bits/stdc++.h>

using namespace std;


int main() {
    int R, G, B, N;
    int r, g, b, nr, ng;
    int res = 0;

    cin >> R >> G >> B >> N;

    r = N / R;

    for (int i = r; i >= 0; i--) {
        nr = N - (R * i);
        g = nr / G;
        for (int j = g; j >= 0; j--) {
            ng = nr - (G * j);
            b = ng % B;
            if (b == 0) {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}
