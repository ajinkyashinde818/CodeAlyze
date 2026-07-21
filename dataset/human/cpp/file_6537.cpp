#include <iostream>
using namespace std;
int n, M=1e9+7; string s;
int main() {
    cin >> n >> s;
    for(int i = 0; i < n*2; i+=2) s[i] = (s[i]=='B' ? 'W' : 'B');

    long A=1, L=0, R=0;
    for(int i=0; i < n*2; ++i) {
        if(s[i]=='W') L++;
        else A = A*(L - R++)%M;
    }
    if(L!=R || s[0]=='B' || s[n*2-1]=='W') { cout << 0; return 0; }

    for(; n>1; A = A*n%M, --n);
    cout << A;
}
