#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i=0; i*r<=n; i++){
        for(int j=0; j*g<=n; j++){
            if((-r*i - g*j + n) % b == 0 && (-r*i - g*j + n) >= 0) ans++;
        }
    }
    cout << ans << endl;
}
