#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <complex>
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
using namespace std;
typedef long long ll;

int main(){
    int n, r;
    cin >> n >> r;
    if(n >= 10) cout << r << endl;
    else cout << r + 100*(10-n) << endl;
    
    return 0;
}
