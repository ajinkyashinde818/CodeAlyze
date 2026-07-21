#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int count = 0;

    for (int i = 0; i <= 3000; ++i) {
        if (R*i > N) break;
        for (int j = 0; j <= 3000; ++j) {
            if (R*i + G*j > N) break;
            if ((N - (R*i + G*j)) % B == 0) count++;
        }
    }

    cout << count << endl;
}
