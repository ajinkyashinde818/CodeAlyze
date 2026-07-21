#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i=0; i < n/r + 2;i++){
        for(int j=0; j< (n-r*i)/g + 2; j++){
            if((r*i + g*j) <= n && (n-r*i-g*j) % b == 0){
                ans ++ ;
            }
        }
    }
    cout << ans << endl;
    
}
