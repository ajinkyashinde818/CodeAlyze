#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

typedef long long ll;
using namespace std;

ll Mod = 1e9 + 7;
int main()
{
    int R, G, B, N, ans = 0;
    cin >> R >> G >> B >> N;

    for (int i = 0; i <= N/R; i++) {
        for (int j = 0; j <= N/G; j++) {
            if (i*R + j*G > N) continue;
            if ((N - i*R - j*G) % B == 0) {  
                ans++;
                //cout << i << " " << j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
