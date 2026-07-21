#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    vi data(N, 0);
    int count = 0, MIN = 1000000000;
    for (int i = 0; i < N; i++) {
        cin >> data[i];
        if (data[i] < 0) {
            count++;
        }
        if (abs(data[i]) < abs(MIN)) {
            MIN = data[i];
        }
    }
    ll ans = 0;
    for (int x : data) {
        ans += ll(abs(x));
    }
    if (count % 2 == 1) {
        ans -= ll(abs(MIN)) * 2;
    }
    cout << ans << endl;
}
