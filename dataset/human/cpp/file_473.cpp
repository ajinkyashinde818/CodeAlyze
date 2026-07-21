#include "bits/stdc++.h"

using namespace std;

int main(){
    int R, G, B, N, ans;
    cin >> R >> G >> B >> N;
    
    ans = 0;
    
    for(int i = 0; i <= N/R; i++)
    {

        for(int j = 0; j <= N/G; j++)
        {
            
            if ((N - R*i - G*j) % B == 0 && (N - R*i - G*j) >= 0) {
                ans += 1;
            }
            
        }
        
    }
    
    cout << ans << endl;
}
