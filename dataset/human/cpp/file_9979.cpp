#include <bits/stdc++.h>
using namespace std;

int main(){
    long N;
    cin >> N;
    string s;
    cin >> s;

    array<long, 256> countchar{};

    for(char i : s){
        countchar[i] = countchar[i] + 1;
    }

    long ans = 1;

    for(long i : countchar){
        ans = ans * (i + 1) % 1000000007;
    }

    cout << ans - 1 << endl;

    return 0;
}
