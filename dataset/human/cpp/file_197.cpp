#include <iostream>
using namespace std;
 
int main() {
    int r, g, b, n, sum, ans = 0;
    cin >> r >> g >>  b >>  n;
    for(int i = 0; i <= n/r; ++i){
        for(int j = 0; j <= n/g; j++){
            sum = n - (i*r+j*g);
            if(sum < 0) {
                break;
            } else if(sum%b == 0) {
                ans++;
            }
        }
    }
 
    cout << ans << '\n';
}
