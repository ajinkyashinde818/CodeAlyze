#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> a(N);
    vector<string> b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];
    bool flag = true;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(x + M - 1 >= N || y + M - 1 >= N) continue;
            flag = true;
            for(int i = 0; i < M; i++){
                for(int j = 0; j < M; j++){
                    int xx = x + i;
                    int yy = y + j;
                    if(a[xx][yy] != b[i][j]) flag = false;
                }
            }
            if(flag) break;  
        }
        if(flag) break;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
