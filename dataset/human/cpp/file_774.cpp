#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;

    for(int i = 0;i <= 3000;i++){
        for(int j = 0;j <= 3000;j++){
            if((n - (i * r) - (j * g)) / b >= 0 && (n - (i * r) - (j * g)) % b == 0){
                ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}
