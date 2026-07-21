#include<bits/stdc++.h>

using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    int r,g;
    for(r=0;r<=N;r++){
        for(g=0;g<=N;g++){
            if(N-r*R-g*G >= 0 && (N-r*R-g*G) % B == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
