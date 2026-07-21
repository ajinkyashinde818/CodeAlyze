#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    long long res = 0;
    for (int r=0; r<=N; r+=R) {
        for (int g=0; r+g<=N; g+=G) {
            if ((N - r - g) % B == 0) {
                res ++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
