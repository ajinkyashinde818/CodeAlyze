#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;
    cin >> N >> M;
    string A[N],B[M];
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<M;i++) cin >> B[i];

    for(int i=0;i<N-M+1;i++){
        for(int k=0;k<N-M+1;k++){
            bool match=true;
            for(int j=0;j<M;j++){
                if(A[i+j].substr(k,M) != B[j]) match=false;
            }
            if(match){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
