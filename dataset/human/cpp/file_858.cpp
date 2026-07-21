#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, n;
    int ans = 0;

    cin >> a >> b >> c >> n;

    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            if ((n - (i*a + j*b)) >= 0 && (n - (i*a + j*b)) % c == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
