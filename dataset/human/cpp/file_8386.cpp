#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;
    string A[N],B[M];

    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<M;i++)
        cin>>B[i];
    bool ans=false;

    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            bool eq=true;
            for(int k=0;k<M;k++){
                string sub=A[i+k].substr(j,M);
                if(sub!=B[k]){
                    eq=false;
                    break;
                }
            }
            if(eq){
                ans=true;
                break;
            }
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}
