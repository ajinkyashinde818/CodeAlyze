#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <typeinfo>
#include <list>
#include <queue>
#include <stack>
#include <limits.h>
#include <set>
#include <map>
using namespace std;


int main() {
    int N;
    string S;
    cin>>N>>S;
    map<char, long long> m;
    for (char s:S) {
        m[s]++;
    }
    long long ans = 1, mod = 1e9+7;
    for (auto e:m) {
        if (e.second > 1) {
            ans = (e.second + 1) * ans % mod;
        }
        else {
            ans = ans * 2 % mod;
        }
    }
    cout<<(ans-1) % mod<<endl;
    return 0;
}
