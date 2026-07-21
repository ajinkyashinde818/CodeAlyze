#include <bits/stdc++.h>
using namespace std;

long long md(pair<long long,long long> x,pair<long long,long long> y){
    return max(x.first,y.first)-min(x.first,y.first)+max(x.second,y.second)-min(x.second,y.second);
}

int main(){
    int N,M;
    cin >> N >> M;
    char A[N][N],B[M][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cin >> B[i][j];
        }
    }
    bool flag=1;
    string ans="No";
    for(int i=0;i<N-M+1;i++){
        for(int j=0;j<N-M+1;j++){
            flag=1;
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(A[k+i][l+j]!=B[k][l]){
                        flag=0;
                    }
                }
            }
            if(flag)
            ans="Yes";
        }
    }
    cout << ans << endl;
}
