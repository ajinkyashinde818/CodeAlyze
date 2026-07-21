#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M;
    bool flag = false;
    cin >> N >> M;
    vector<string> A(N),B(M);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    for(int i=0;i<M;i++){
        cin >> B[i];
    }

    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            flag = false;
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(A[i+k][j+l] != B[k][l]){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }

            if(!flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
