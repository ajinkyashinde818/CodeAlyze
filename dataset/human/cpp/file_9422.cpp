#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<string> A(N),B(M);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        cin>>B[i];
    }
    for(int i=0;i<N-M+1;i++){//点の座標
        for(int j=0;j<N-M+1;j++){
            for(int k=0;k<M;k++){
                if(A[j+k].substr(i,M)!=B[k]){break;}
                if(k==M-1){cout<<"Yes"<<endl;exit(0);}
            }
        }
    }
    cout<<"No"<<endl;
}
