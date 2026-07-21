#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    int n;cin >> n;
    int e[26];
    for(int i = 0;i < 26;i++) e[i] = 0;
    for(int i = 0;i < n;i++){
        char z; cin >> z;
        e[z - 'a']++;
    }
    ll result = 1;
    ll big = 1e9 + 7;
    for(int i = 0;i <  26;i++){
        result = result * (e[i] + 1) % big;
    }
    result -= 1;
    result %= big;

    cout << result << endl;
}
