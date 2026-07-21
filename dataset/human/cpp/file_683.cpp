#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
 
    int i, j, k, ans = 0;
    for (i=0; ; i++){
        if (i*R == N){
            ans++;
        }        
        if (i*R >= N){
            break;
        }
 
        for (j=0; ; j++){
            if (i*R + j*G == N){
                ans++;
            }
            if (i*R + j*G >= N){
                break;
            }
 
            if ((N - (i*R + j*G))%B == 0  ){
                ans++;
            }
        }
    }
 
 
    cout << ans;
 
    return 0;
}
