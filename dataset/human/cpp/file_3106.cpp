#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;
#define int long long


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i ++){
        cin >> a.at(i);
    }

    int count = 0;
    for(int i = 0;i < n;i ++){
        if(a.at(i) < 0) count ++;
    }

    for(int i = 0;i < n;i ++) a.at(i) = abs(a.at(i));

    sort(a.begin(),a.end());

    int ans = 0;
    if(count % 2 == 0) ans += a.at(0);
    else ans -= a.at(0);

    for(int i = 1;i < n;i ++) ans += a.at(i);

    cout << ans << endl;
}
