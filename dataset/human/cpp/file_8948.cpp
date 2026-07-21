#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,M;
    cin >> N >> M;
    vector<vector<char>> A(N,vector<char>(N)),B(M,vector<char>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++) cin >> B[i][j];
    }
    bool f = true;
    for(int i = 0; i < N-M+1; i++){
        for(int j = 0; j < N-M+1; j++){
            f =true;
            for(int s = 0; s < M; s++){
                for(int t = 0; t < M; t++){
                    if(A[i+s][j+t] != B[s][t]){
                        f = false;
                        break;
                    }
                }
                if(f == false) break;
            }
            
            if(f == true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
