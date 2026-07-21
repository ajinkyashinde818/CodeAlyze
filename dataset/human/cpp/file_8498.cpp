#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
//priority_queue<int> pque;
//priority_queue<int, vector<int>, greater<int>> pque;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 1000000000;//10^9
ll MOD  = 1000000007;


int main(void){
    int N,M;
    cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(M, vector<char>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> B.at(i).at(j);
        }
    }
    bool OK = 0;
    for(int i = 0; i <= N-M; i++){
        for(int j = 0; j <= N-M; j++){
            bool ok = 1;
            for(int a = 0; a < M; a++){
                for(int b = 0; b < M; b++){
                    if(A.at(i+a).at(j+b) != B.at(a).at(b)){
                        ok = 0;
                    }
                }
            }
            if(ok){
                OK = 1;
            }
            
            
        }
    }
    
    if(OK){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
    
}
