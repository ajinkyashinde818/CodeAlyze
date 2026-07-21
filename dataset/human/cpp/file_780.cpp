#include <iostream>

using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int rmax = N / R;
    int gmax = N / G;
    int count = 0;
    for (int r = 0; r <= rmax; ++r) {
        for (int g = 0; g <= gmax; ++g) {
            int mid = R * r + G * g;
            if (mid > N) continue;
            if ((N - mid) % B != 0) continue;
            else ++count;
        }
    }
    cout << count << endl;
    return 0;
}
