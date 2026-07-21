#include<bits/stdc++.h>

using namespace std;
int main(void) {
    long MOD = 1e9 + 7;
    long n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> t(2*n);

    long k=0;
    for(int i=0; i<2*n; i++) {
        int c = s[i] == 'B' ? 1 : 0;
        if((c+k)%2 == 0) {k--; continue;}
        t[i] = true;
        k++;
    }
    //for(auto x: t) cout << x << endl;
    if(k!=0) {cout << 0 << endl; return 0;}

    long r = 1;
    long tt = 0;
    for(int i=0; i<2*n; i++) {
        if(t[i]) {
            // open
            tt++;
        } else {
            r *= tt;
            r %= MOD;
            tt--;
        }
    }
    for(int i=1; i<=n; i++)
        r *= i, r %= MOD;
    cout << r << endl;
}
