#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, M; cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    bool check = false;
    bool tmp = true;
    for (int i = 0; i < N-M+1; i++) {
        for (int j = 0; j < N-M+1; j++) {
            tmp = true;

            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if(A[i+k][j+l] != B[k][l]){
                        tmp = false;
                        break;
                    }
                }
                if(tmp == false){
                    break;
                }
            }

            if(tmp == true){
                check = true;
            }

        }
    }

    if(check == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

}
