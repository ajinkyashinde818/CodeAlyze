#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];
    
    bool flag=true, F=false;
    for(int i=0; i<=N-M; i++){
        for(int j=0; j<=N-M; j++){
            flag=true;
            for(int k=0; k<M; k++){
                if(A[i+k].substr(j,M) != B[k])
                    flag = false;
            }
            if(flag) F=true;
        }
    }
    
    cout << (F?"Yes":"No") << endl;
}
