#include <iostream>

using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int count = 0;
    int max_r, max_g, max_b;
    max_r = N / R;
    max_g = N / G;
    max_b = N / B;

    for (int i = 0; i < max_r + 1; i++){
        for (int j = 0; j < max_g + 1; j++){
            if ((N - (R * i + G * j)) % B == 0 and N - (R * i + G * j) >= 0)
                count++;
        }
    }

    cout << count << endl;
}
