#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,M;
vector<string> A,B;

bool isMatch(int sy,int sx){
    for(int i=0;i<M;i++)for(int j=0;j<M;j++){
        int y = sy +i;
        int x = sx+j;
        if(A[y][x] != B[i][j]){
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N >>M;
    A.resize(N);
    B.resize(M);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<M;i++){
        cin >> B[i];
    }
    for(int i=0;i<=(N-M);i++)for(int j=0;j<=(N-M);j++){
        if(isMatch(i,j)){
            cout <<"Yes"<<endl;
            return 0;
        }
    }
    cout <<"No"<<endl;

    return 0;
}
