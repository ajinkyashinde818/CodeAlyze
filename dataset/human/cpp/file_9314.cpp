#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    
    for(int i = 0; i < N - M + 1; i++){
        for(int j = 0; j < N - M + 1; j++){
            
            bool ok = true;
            for(int a = 0; a < M; a++){
                for(int b = 0; b < M; b++){
                    if(A[i+a][j+b]!=B[a][b])ok = false;
                }
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
