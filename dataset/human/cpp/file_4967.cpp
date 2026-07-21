#include <bits/stdc++.h>
using namespace std;
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);} } fast;
 
long long mod = 1000000007;
 
long long div(long long a, long long b, long long c){
    return b / c - (a - 1) / c;
}
 
void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}
 
int main() {
    int k, s, ans = 0;
    cin >> k >> s;
    if (k < 10){
        cout << s + 1000 - k * 100 << endl;
    }else{
        cout << s << endl;
    }
}
