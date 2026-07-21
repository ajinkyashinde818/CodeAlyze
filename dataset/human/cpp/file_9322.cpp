#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;

int main(){
    int N,M;
    cin >> N >> M;
    char a[N][N];
    char b[M][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cin >> b[i][j];
        }
    }
    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            int count=0;
            for(int u=0;u<M;u++){
                for(int v=0;v<M;v++){
                    if(a[i+u][j+v]==b[u][v]) count++;
                    if(count==M*M){
                        puts("Yes");
                        return 0;
                    }
                }
            }
        }
    }
    puts("No");
    return 0;
}
