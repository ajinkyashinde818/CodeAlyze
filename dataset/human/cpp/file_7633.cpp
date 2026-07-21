#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <numeric>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
const int BG = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    int64_t sum = 0;
    rep(i, N)
    {
        int64_t input;
        cin >> input;
        v[i] = input;
        sum += input;
    }

    int64_t mini = 1001001001001;

    int64_t flont = 0;

    int flag = 1;

    rep(i, N - 1)
    {
        flag = 0;
        flont += v[i];
        sum -= v[i];
        mini = min(mini, abs(sum - flont));
    }
    if (flag)
    {
        cout << abs(v[1] - v[0]) << endl;
        return 0;
    }
    cout << mini << endl;
    return 0;
}
