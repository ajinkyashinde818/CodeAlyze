#include <iostream>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto c: s){
        cnt[c]++;
    }

    long long ans = 1; 
    for(auto t: cnt){
        ans = (ans * (t.second+1)) % MOD;
    }

    cout << ans - 1 << endl;

    return 0;
}
