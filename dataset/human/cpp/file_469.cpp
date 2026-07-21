#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 1e6 + 1;

int r, g, b, n, ans;
int main(){
    cin >> r >> g >> b >> n;
    for(int i = 0; i <= n / r; i++){
        for(int j = 0; j <= n / g; j++){
            int h = n - (r * i) - (j * g);
            if(h < 0){
                continue;
            }
            if(h % b == 0){
                ans++;
            }
        }
    }
    cout << ans;
}
