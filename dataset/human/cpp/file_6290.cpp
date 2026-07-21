#include <bits/stdc++.h>
using namespace std;

constexpr int64_t mod = 1'000'000'007; //'

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    int64_t dp = 1;
    int64_t over = 1;

    if(s[0] == 'W' || s[2*n-1] == 'W'){
        cout << 0 << endl;
        return 0;
    } 

    for(int i=1;i<2*n;i++){
        int stat = (s[i]=='B' ? 0 : 1);
        if((stat + over) % 2 == 1){
            dp = dp * over % mod;
            over--;
        }else{
            over++;
        }
    }

    int64_t fact = 1;
    for(int i=1;i<=n;i++) fact = i*fact % mod;
    if(over == 0){
        cout << dp*fact%mod << endl;
    }else{
        cout << 0 << endl;
    }
    
    return 0;
}
