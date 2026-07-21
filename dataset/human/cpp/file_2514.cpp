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
    int N;
    cin >> N;
    vector<int> a(N);
    int c = 0;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        int b;
        cin >> b;
        if(b < 0) c++;
        a[i] = max(b,-b);
        sum += max(b,-b);
    }
    if(c % 2 == 0) cout << sum << endl;  
    else{
        sort(a.begin(),a.end());
        cout << sum - 2*a[0] << endl;
    }
    return 0;
}
