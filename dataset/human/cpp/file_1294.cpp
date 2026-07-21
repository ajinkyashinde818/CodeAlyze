#include <bits/stdc++.h>
using namespace std;
int main(void){
    int R, G, B, N;
    int ans = 0;
    cin >> R >> G >> B >> N;
    for (int r=0; r <= N; r++){
        for (int g = 0; g <= N; g++){
            if ((N - r*R - g*G) % B == 0 && (N - r*R - g*G) >= 0){
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
