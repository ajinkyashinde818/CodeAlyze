#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cstdint>   // int64_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iomanip>   // setprecision
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <utility>       // pair, make_pair
#include <vector>        // vector
using namespace std;

int gcd(long long a, long long b) { return b != 0 ? gcd(b, a % b) : a; }
// cout << fixed << setprecision(10);
// vector<vector<int>> vec(H, vector<int>(W))    // int H*W

int main() {
    int N, R;
    cin >> N >> R;
    int ans = R;
    if(N < 10) {
        ans += 100* (10-N);
    }
    cout << ans << endl;

}
