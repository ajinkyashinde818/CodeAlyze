#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    long long res = 0;
    for(int r=0; r<=N; ++r) {
        for(int g=0; g<=N; ++g) {
            int tmp = N - r * R - g * G;
            if(tmp >= 0 && (tmp % B == 0)) ++res;
        }
    }
    cout << res << endl;
}
