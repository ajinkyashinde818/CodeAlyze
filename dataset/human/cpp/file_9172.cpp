#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int N,M;
    cin>>N>>M;
    vector<string> A(N),B(M);
    for (int i=0;i<N;i++) cin>>A[i];
    for (int i=0;i<M;i++) cin>>B[i];

    for (int i=0;i<N-M+1;i++){
        for (int j=0;j<N-M+1;j++){
            bool flag = true;
            for (int k=0;k<M;k++){
                if (A[i+k].substr(j,M)!=B[k]) flag = false;
            }
            if (flag) {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
