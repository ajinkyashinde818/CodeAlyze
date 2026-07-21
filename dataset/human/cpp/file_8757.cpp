#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<string> A(N),B(M);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(A[i+k][j+l]!=B[k][l]) goto skip;
                }
            }
         	goto Yes;
          	skip:;
        }
    }
    cout<<"No"<<endl;
    return 0;
    Yes:cout<<"Yes"<<endl;
}
