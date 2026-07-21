#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b){if(a < b){ a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b){if(a > b){ a = b; return 1;} return 0;}

const ll INF = 1000000000;

int main(){
    int n, r;
    cin >> n >> r;

    if(n >= 10){
        cout << r << endl;
    }else{
        cout << r + 100 * (10 - n) << endl;
    }
    
    
    return 0;
}
