#include <iostream>
using namespace std;

int main(void) {
    int R,G,B,N;cin>>R>>G>>B>>N;
    int result = 0;
    for (int r = 0; r <= N / R; r++) {
        for (int g = 0; g <= N / G; g++) {
            if (R * r + G * g > N) break;
            if ((N - r * R - g * G) % B == 0) result++;
        }
    }
    cout << result << endl;
    return 0;
}
