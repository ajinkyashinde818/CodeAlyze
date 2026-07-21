#include<iostream>
using namespace std;

//input
int R, G, B, N;

int main() {
    cin >> R >> G >> B >> N;

    long long count = 0;
    for (int i = 0; i < 3001; ++i) {
        for (int j = 0; j < 3001; ++j) {
            int ret = N - R * i - G * j;
            if (0 <= ret && ret % B == 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}
