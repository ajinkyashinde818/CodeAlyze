#include <iostream>
#include <string>

using namespace std;

int main() {
    int R,G,B,N; cin >> R >> G >> B >> N;
    int ans = 0;
    for(int r=0; r <= N; r++) {
        for(int g=0; g <= N; g++) {
            if(N >= (g*G + r*R) && (N - (g*G + r*R)) % B == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

}
