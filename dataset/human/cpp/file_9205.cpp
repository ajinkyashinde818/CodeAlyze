#include <bits/stdc++.h>
using namespace std;
int N,M;
string A[55];
string B[55];
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int fail=0;
            for(int k=0;k<M;k++){
                for(int s=0;s<M;s++){
                    if(i+k>=N){
                        fail=1;
                        break;
                    }
                    if(j+s>=N){
                        fail=1;
                        break;
                    }
                    if(A[i+k][j+s]!=B[k][s]){
                        fail=1;
                        break;
                    }
                }
            }
            if(!fail){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
