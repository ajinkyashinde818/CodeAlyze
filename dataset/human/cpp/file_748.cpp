#include <bits/stdc++.h>
using namespace std;


int main() {
    int r,g,b,n;
    long long cnt = 0;
    cin >> r >> g >> b >> n;
    for(int i = 0 ; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int x = n - i*r - j*g;
            if(x % b == 0 & x / b <= n && x >= 0){
                cnt++;
                //cout << i << " " << j << " " << x/b << endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
