#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int R, int G, int B, int N, ll &ans){

    for(int r = 0; r*R <= N; ++r){
        for(int g = 0; g*G <= N; ++g){
            int b = (N - (r*R + g*G))/B;
            int b_mod = (N - (r*R + g*G))%B;

            if((b >= 0) && (b_mod == 0)) ++ans;
        }
    }

    return;
}

int main(){

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans{};
    solver(R, G, B, N, ans);

    cout << ans << endl;
    
    return 0;
}
