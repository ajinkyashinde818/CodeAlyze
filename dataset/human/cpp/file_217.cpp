#include <iostream>
#include <string>

using namespace std;

int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;

    long res = 0;
    for (int i = 0; (i * R) <= N; ++i) {
        int cr = i * R;
        for (int j = 0; (cr + j * G) <= N; ++j) {
            int cg = cr + j * G;
            if ((N - cg) % B == 0) { ++ res; }
        }
    }

    cout << res << endl;
}
