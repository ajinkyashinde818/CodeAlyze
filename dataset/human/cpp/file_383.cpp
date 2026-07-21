#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int RR = N / R + 1;
    int GG = N / G + 1;
    int BB = N / B + 1;
    int count = 0;

    for (int i = 0; i < RR; i++) {
        for (int j = 0; j < (N - R * i) / G + 1; j++) {
            if ((N - R * i - G * j) % B == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
}
