#include <bits/stdc++.h>
using namespace std;

int N, M;
// 画像A, テンプレート画像B
char A[50][50], B[50][50];

bool check(int y, int x){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(A[y+i][x+j] != B[i][j])
                return false;
        }
    }
    return true;
}
 
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> A[i][j];
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            cin >> B[i][j];
    
    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            if( check(i, j) ){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

}
