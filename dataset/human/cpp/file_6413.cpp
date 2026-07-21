#include "bits/stdc++.h"

using namespace std;

const int mod = 1e9 + 7;

int main()  {
    int n;
    cin >> n;
    
    n *= 2;
    
    string s;
    cin >> s;
    
    if (s[0] == 'W') return cout << "0\n", 0;
    
    vector< int> dat(n);
    for (int i = 0; i < n; i ++) dat[i] = (s[i] == 'B'? 1 : 0);
    
    int result = 1;
    int cnt = 0;
    
    for (int i = 0; i < n; i ++) {
        if (dat[i] != cnt % 2) {
            cnt ++;
        }
        else {
            result = result * 1LL * cnt % mod;
            cnt --;
        }
        if (cnt < 0) return cout << "0\n", 0;
    }
    if (cnt != 0) return cout << "0\n", 0;
    
    int fact = 1;
    for (int i = 2; i <= n / 2; i ++) fact = fact * 1LL * i % mod;
    result = result * 1LL * fact % mod;
    cout << result << endl;
}
