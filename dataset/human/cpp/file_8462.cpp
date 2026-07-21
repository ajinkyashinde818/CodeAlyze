#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;
    char A[N][N];
    char B[M][M];
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
    bool ok = false;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i+M-1>=N||j+M-1>=N)continue;

            bool match = true;
            for(int y=0;y<M;y++){
                for(int x=0;x<M;x++){
                    if(A[i+y][j+x]!=B[y][x]){
                        match = false;
                        break;
                    }
                }
            }
            if(match) ok =true;
        }
    }

    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
