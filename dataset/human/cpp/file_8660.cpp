#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;

    string A[N];
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    string B[M];
    for(ll i = 0; i < M; i++){
        cin >> B[i];
    }

    string ans = "No";

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i + M - 1 >=N or j + M -1 >= N) continue;

            bool match = true;
            for(ll k = 0; k < M; k++){
                for(ll l = 0; l < M; l++){
                    if(A[i + k][j + l] != B[k][l])match = false;
                }
            }

            if(match){
                ans = "Yes";
            }

        }
    }


    cout << ans << endl;

    return 0;
}
