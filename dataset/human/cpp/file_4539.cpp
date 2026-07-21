#include <bits/stdc++.h>

using namespace std;

const double inf = 1e8;

template<typename T> inline void chmin(T& t, T f){if(t > f)t = f;}

int main(){
    int T, D, tA, tB, dA, dB;
    cin >> T >> D >> tA >> tB >> dA >> dB;
    double ans = inf;
    for(int vA=0; vA<=D; vA+=dA){
        for(int vB=0; vA+vB<=D; vB+=dB){
            if(vA + vB == 0)continue;
            chmin(ans, abs(T - 1.0 * (tA * vA + tB * vB) / (vA + vB)));
        }
    }
    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}
