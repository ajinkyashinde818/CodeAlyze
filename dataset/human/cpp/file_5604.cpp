#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <utility>
#include <queue>
#include <tuple>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
constexpr ll INF = 1000000007;

int main() {
    int r, n;
    cin >> n >> r;
    if (n >= 10)cout << r << endl;
    else cout << r + 100 * (10 - n) << endl;
    
    return 0;
}
