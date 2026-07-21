#include <iostream>

using namespace std;

int main(){

    int R, G, B, N;
    cin >> R >> G >> B >> N;
    
    int ans = 0;
    
   
    
    for (int r = 0; r <= int(N/R); r++) {
        int ss = N - r*R;
        for (int g = 0; g <= int(ss/G); g++) {
            int vv = ss - g*G;
            if(vv%B == 0){
                ans += 1;
            }
            
        }
    }
    
    
    
    
    cout << ans << endl;
    
    
    
    
    
    return 0;
    
}
