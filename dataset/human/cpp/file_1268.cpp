#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    
    int ans = 0;
    for(int i = 0; i <= 3000; i++){
        for(int j = 0; j <= 3000; j++){
            //binary search
            int  l = 0; int R = 3001;
            while(R-l > 1){
                int mid = (l+R)/2;
                if(r*i+g*j+b*mid <= n) l = mid;
                else R = mid;
            }
            if(r*i+g*j+b*l == n) {ans += 1;
            }
            //
        }
    }
    cout << ans << endl;
}
