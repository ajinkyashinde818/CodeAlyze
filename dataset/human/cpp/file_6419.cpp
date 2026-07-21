#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

void fail(){
    cout << 0 << endl;
    exit(0);
}

int main(){
    int N;
    string S;
    cin >> N >> S;
    int64_t ans = 1;
    int now = 0;
    for(int i=0; i<2*N; i++){
        if(S[i] == 'W'){
            if(now == 0) fail();
            if(now%2){
                now++;
            }else{
                mul(ans, now);
                now--;
            }
        }else{
            if(now%2){
                mul(ans, now);
                now--;
            }else{
                now++;
            }
        }
    }
    if(now != 0) fail();
    for(int i=2; i<=N; i++) mul(ans, i);
    cout << ans << endl;
    return 0;
}
