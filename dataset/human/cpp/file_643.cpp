#include <bits/stdc++.h>

using namespace std;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    int nr = n / r;
    int ng = n / g; 
    for(int i = 0; i < nr + 1; i++){
        for(int j = 0; j < ng + 1; j++){
            int tmp = n - i * r - j * g;
            if(tmp >= 0 && tmp % b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
