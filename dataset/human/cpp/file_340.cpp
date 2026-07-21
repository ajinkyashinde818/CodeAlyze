#include <iostream>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int res = 0;
    for (int i = 0; i <= N / R; i++) {
        for (int j = 0; j <= N / G; j++) {
            int rest = N - i * R - j * G;
            if (rest % B == 0 && rest >= 0) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
