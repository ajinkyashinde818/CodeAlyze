#include <iostream>
using namespace std;

int main () {
    int R, G, B, N;
    int ans = 0;
    cin >> R >> G >> B >> N;
    for (int i = 0; i <= N; i++) {
        if (R * i <= N) {
            for (int j = 0; j <= N; j++) {
                if (R * i + G * j <=N) {
                    if ((N - R * i - G * j ) % B == 0) {
                        ans++;
                    }
                }
                else {
                    break;
                }
            }
        }
        else {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
