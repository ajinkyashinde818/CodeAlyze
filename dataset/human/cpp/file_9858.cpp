#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    map<char, int> cnt; 
    const int mod = 1e9 + 7;

    for (char c : S) cnt[c] += 1; 

    long long ans = 1;

    for (auto p : cnt) {
        ans = ans * (p.second + 1) % mod;
    }
    
    cout << (ans + mod - 1) % mod << endl;
    return 0;
}
