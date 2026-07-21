#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    vector<char> A(N*N);
    vector<char> T(M*M);
    for(int i = 0;i < N*N ;i++){
        cin >> A[i];
    }
    for(int i = 0;i < M*M;i++){
        cin >> T[i];
    }
    int ans = 0;
    if(N == M && N == 1){
        if(A[0] == T[0]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
    for(int i = 0 ;i < N - M;i++){
        for(int j = 0;j < N - M;j++){
            bool judje = 1;
            for(int k = 0;k < M;k++){
                for(int l = 0;l < M;l++){
                    if(T[l+k*M] != A[i*N+j+k*N+l]) judje = 0;
                }
            }
            if(judje) ans++;
        }
    }
    if(ans > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    }
}
