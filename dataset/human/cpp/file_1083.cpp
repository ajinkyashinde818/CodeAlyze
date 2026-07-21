#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int R,G,B,N;cin >> R >> G >> B >> N;
    int ans = 0;
    for(int a = 0;a < N/R+1;a++){
        for(int b = 0;b < N/G+1;b++){
            int w = R * a + b * G;
            int d = N - w;
            int c;
            if(d >= 0)c = d/B;
            else continue;
            if(a * R + b * G + c * B == N){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
