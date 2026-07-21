#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <tuple>
using namespace std;

const int MOD = 1e9 + 7;

int main(){

    int n; cin >> n;

    string str;
    cin >> str;

    map<char, int> m;

    for(int i=0; i<n; i++){
        if(m.find(str[i]) == m.end()){
            m.insert(make_pair(str[i],1));
        }
        else{
            m[str[i]]++;
        }
    }

    map<char, int>::iterator itr;

    long long cnt = 1;
    for(itr = m.begin(); itr != m.end(); itr++){
        pair<char, int> p = *itr;
        cnt = (cnt * (p.second + 1)) % MOD;
    }

    cout << cnt - 1;

    return 0;
}
