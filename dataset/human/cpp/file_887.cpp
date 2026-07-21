#include <iostream>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ir = N / R;

    int ans = 0;
    for (int i = 0; i <= ir; i++) {
        int ig = (N - i * R) / G;
        for (int j = 0; j <= ig; j++)
        {
            int tmp = i * R + j * G;
            if (tmp <= N && ((N - tmp) % B == 0))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
