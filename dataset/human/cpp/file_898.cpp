#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    ll ans=0;
    for(int i=0;i<=n/r;i++){
        for(int j=0;j<=(n-i*r)/g;j++){
            if((n-i*r-j*g)%b==0)ans++;
        }
    }
    cout << ans << endl;
}
