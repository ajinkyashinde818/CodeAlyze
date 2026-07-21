#include <bits/stdc++.h>
using namespace std;
int N,M;
int main(){
    cin>>N>>M;
    string a[N],b[M];

    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<M;i++) cin>>b[i];

    for(int i=0;i<N-M+1;i++){
        for(int j=0;j<N-M+1;j++){
            if(a[i][j]==b[0][0]){
                for(int k=0;k<M;k++){
                    for(int l=0;l<M;l++){
                        if(a[i+k][j+l]!=b[k][l]){
                            goto A;
                        }
                    }
                }
                cout<<"Yes"<<"\n";
                return 0;
            }
            A:;
        }
    }
    cout<<"No"<<"\n";
    return 0;
}
