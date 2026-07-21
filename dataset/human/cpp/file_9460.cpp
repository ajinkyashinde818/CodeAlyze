#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    char A[N][N];
    char B[M][M];
    for(int i=0;i<N;i++){
        string a; cin >> a;
        for(int j=0;j<N;j++){
            A[i][j]=a[j];
        }
    }
    for(int i=0;i<M;i++){
        string b; cin >> b;
        for(int j=0;j<M;j++){
            B[i][j]=b[j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            bool flag=true;
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(i+k>=N||j+l>=N){
                        flag=false;
                        break;
                    }
                    if(B[k][l]==A[i+k][j+l]) continue;
                    flag=false;
                    break;
                }
                if(!flag) break;
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
