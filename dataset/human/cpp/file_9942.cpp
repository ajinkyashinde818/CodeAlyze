#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int add(int i, int j) {
    if((i += j) >= mod) i -= mod;
    return i;
}

int mult(int i, int j) {
    return (ll) i * j % mod;
}

int A[26];

int main() {
    int n; cin >> n;
    char c;
    while(n--) {
        cin >> c;
        A[c - 'a'] += 1;
    }
    
    int mx = 1;
    
    for(int i = 0; i < 26; ++i)
        mx = mult(mx, A[i] + 1);
    
    cout << mx - 1;
    
    return 0;
}
