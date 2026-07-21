#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
long long MOD = 1e9 + 7;
int main(){
    long long N;
    cin >> N;
    string S;
    cin >> S;
    map<char, long long> m;
    for(int i = 0; i < N; i++){
        m[S[i]]++;
    }
    long long ans = 1;
    for(auto v: m){
        ans *= (v.second + 1);
        ans %= MOD;
    }
    ans -= 1;
    cout << (ans + MOD) % MOD << endl;
}
