#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, n;
    cin >> R >> G >> B >> n;

    int cnt = 0;
    for (int r = 0; R * r <= n; r++)
    {
        for (int g = 0; G * g<= n - R * r; g++)
        {
            if ((n - R * r - G * g) % B == 0) cnt++;  
        }  
    }
    cout << cnt << endl;
}
