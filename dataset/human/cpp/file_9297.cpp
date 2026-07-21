#include "bits/stdc++.h"
using namespace std;
int main(){
    int N,M,i,j,ans=0,tmp;
    cin >> N >> M;
    char A[N][N], B[M][M];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            cin >> B[i][j];
        }
    }
    int y0,x0;
    for(y0=0;y0<N-M+1;y0++){
        for(x0=0;x0<N-M+1;x0++){
            tmp=1;
            for(i=0;i<M;i++){
                for(j=0;j<M;j++){
                    if(A[y0+i][x0+j]!=B[i][j]) tmp=0;
                }
            }
            if(tmp) ans = 1;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
