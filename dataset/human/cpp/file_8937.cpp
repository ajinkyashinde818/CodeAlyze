#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
main(){
    int N,M;
    string A[51],B[51];
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < M;i++){
        cin >> B[i];
    }
    for(int i = 0;i <= N-M;i++){
        for(int j = 0;j <= N-M;j++){
            for(int k = 0;k < M;k++){
                if(A[i+k].substr(j,M) != B[k])break;
                if(k==M-1){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}
