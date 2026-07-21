#include <iostream>
#include <string>
using namespace std;

int main(){
    int r, g, b, n; cin >> r >> g >> b >> n;
    int max_r = n / r + 1;
    int max_g = n / g + 1;
    int ans = 0;
    for(int i=0; i<max_r; i++){
        for(int j=0; j<max_g; j++){
            int lest = n - r * i - g * j;
            if(lest >= 0 && lest%b == 0){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
