#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int N, M;
bool judge(vector<vector<bool>> &A, vector<vector<bool>> &B, int y, int x){
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            if(A[i+y][j+x] != B[i][j])
                return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(N, false));
    vector<vector<bool>> B(M, vector<bool>(M, false));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            char c;
            cin >> c;
            if(c=='#')
                A[i][j] = true;
        }
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            if(c=='#')
                B[i][j] = true;
        }

    for(int i=0; i<=N-M; i++){
        for(int j=0; j<=N-M; j++){
            if(judge(A, B, i, j)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
