#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
using namespace std;
int main(void){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int k = n / r;
    int ans = 0;
    for(int i=0; i<k+1; i++){
        int l = (n - r*i)/g;
        for(int j=0; j < l+1; j++){
            if((n-r*i-j*g)%b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
