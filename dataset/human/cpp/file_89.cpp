#include <iostream>
using namespace std;

int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;
    int count = 0;

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            // cout << "r, g :" << i << j << endl;
            if(N - R * i - G * j < 0) break;

            if((N - R * i - G * j) % B == 0) {
                count++;
                // cout << "OK: rest is" << N - R * i - G * j  << endl;
            }
        }
        if(N - R * i <= 0) break;
    }

    cout << count << endl;
}
