#include <bits/stdc++.h>
using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int64_t ans = 0;
    for(int r=0;r<=N;r++){
        for(int g=0;g<=N;g++){
            int ball = N - r*R - g*G;
            if(ball < 0 || ball % B != 0) continue;
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
