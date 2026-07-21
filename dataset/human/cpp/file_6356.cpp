#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> s_inverse(2*n);
    for(int i=0; i<2*n; i++){
        if(s[i] == 'B') s_inverse[i] += 1;
        if(i % 2 == 0) s_inverse[i] += 1;
        s_inverse[i] %= 2; 
    }
    //for(int i=0; i<2*n; i++) cout << s_inverse[i];
    //cout << endl;

    long long int ans = 1;
    long long int left = 0;
    for(int i=0; i<2*n; i++){
        if(s_inverse[i] == 0) left += 1;
        if(s_inverse[i] == 1){
            ans *= left;
            ans %= MOD;
            left -= 1;
            if(left < 0){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if(left != 0){
        cout << 0 << endl;
        return 0;
    }

    for(int i=n; i>=1; i--){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
