#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll R,G,B,n,ans=0;
    cin >> R >> G >> B >> n;
    for(int r = 0;r <= n/R;r ++){
        int rem = n-R*r;
        for(int g = 0;g <= rem/G;g ++){
            int rem1;
            rem1 = rem-G*g;
            if(rem1%B==0) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}
