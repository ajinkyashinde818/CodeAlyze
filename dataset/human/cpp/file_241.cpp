#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 R, G, B, N;
    cin >> R >> G >> B >> N;
    i64 ans = 0;
    for(i64 r=0;r<=N/R;++r){
        for(i64 g=0;g<=N/G;++g){
            i64 m = N - r*R - g*G;
            if(m < 0 || m%B != 0)continue;
            i64 b = m / B;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
