#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    int nr = 0;
    while(nr*r <= n){
        int ng = 0;
        while(nr*r + ng*g<=n){
            if((n-nr*r-ng*g)%b == 0){
                ans += 1;
            }
            ng += 1;
        }
        nr += 1;
    }
    cout << ans;
}
