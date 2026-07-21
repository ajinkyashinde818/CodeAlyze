#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> Ai(N, vector<char>(N));
    vector<vector<char>> Bi(M, vector<char>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Ai.at(i).at(j);
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> Bi.at(i).at(j);
        }
    }
    bool exist = false;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i + M - 1 >= N || j + M - 1 >= N) continue;

            bool match = true;
            for(int li = 0; li < M; li++){
                for(int lj = 0; lj < M; lj++){
                    if(Ai.at(i + li).at(j + lj) != Bi.at(li).at(lj)) match = false;
                }
            }
            if(match) exist = true;
        }
    }
    
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
