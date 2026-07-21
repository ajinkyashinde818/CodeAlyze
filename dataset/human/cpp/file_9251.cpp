#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];
    
    int flag=1, ans=0;
    for(int i=0; i<=N-M; i++){
        for(int j=0; j<=N-M; j++){
            flag=1;
            for(int k=0; k<M; k++){
                if(A[i+k].substr(j,M) != B[k])
                    flag = 0;
            }
            if(flag) ans=1;
        }
    }
    
    if(ans) cout << "Yes";
    else cout << "No";
}
