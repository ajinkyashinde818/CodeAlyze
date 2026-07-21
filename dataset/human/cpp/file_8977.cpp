#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    char A[60][60];
    char B[60][60];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> B[i][j];
        }
    }

    bool exist = false;
    for(int ly = 0; ly < N; ++ly){
        for(int lx = 0; lx < N; ++lx){
            if(ly + M - 1 >=  N || lx + M -1 >= N) continue;

            bool match = true;
            for(int y = 0; y < M; y++){
                for(int x = 0; x < M; x++){
                    if(A[ly+y][lx+x] != B[y][x]) match = false;
                }
            }
            if(match) exist = true;
        }
    }
    if(exist) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}
/*
方針はあってた，実装力が身につかない→問題の中で身につけていく必要あり
今回の場合4重のうちの 中側2つはM×Mの全探索
外側2つはN×Nの全探索でif文で例外を除く
for文は基本0~定数でif文continueなどで例外を除く方が良いか
*/
