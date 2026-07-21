#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int R, G, B, N;
int nr, ng;
long long ans = 0;

int main() {
    cin >> R >> G >> B >> N;
    nr = (N + R - 1) / R;
    for (int r=0; r<=nr; ++r) {
        ng = (N-R*r+G-1)/G;
        for (int g=0; g<=ng; ++g) {
            if ((N-R*r-G*g) >= 0 && (N-R*r-G*g) % B == 0) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
