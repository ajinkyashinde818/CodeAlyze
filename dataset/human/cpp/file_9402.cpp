#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

//map<int,int> mmap;

char A[51][51];
char B[51][51];
int main(){

    //freopen("test.in","r",stdin);

    int M,N;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>A[i][j];
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++) cin>>B[i][j];
    }

    bool got = false;
    bool inner = false;

    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){


            inner=true;
            for(int x=0;x<M;x++){
                for(int y=0;y<M;y++){
                    if(A[i+x][j+y]!=B[x][y]){
                        inner = false;
                        break;
                    }
                }
                if(!inner) break;
            }

            if(inner) {
                got=true;
                cout<<"Yes\n";
                return 0;
            }
        }


    }

    cout<<"No\n";

    return 0;
}
