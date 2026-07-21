#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int R, G, B, N; cin >> R >> G >> B >> N;

    int ans = 0;
    for (int i = 0; i*R <= N; i++) {
        for (int j = 0; j*G <= N-i*R; j++) {
            if ((N-i*R-j*G) % B == 0) ans++;
            
        }
    } 

    cout << ans << endl;
}
