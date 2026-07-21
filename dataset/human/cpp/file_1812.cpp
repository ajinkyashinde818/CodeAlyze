#include <utility> // pair make_pair
using std::pair;
using std::make_pair;
#include <tuple> // tuple(c++11) make_tuple(c++11)
using std::tuple; // get<address>(variable)
using std::make_tuple;
#include <string> // string stoi(c++11) stoll(c++11) to_string(c++11)
using std::string;
using std::stoi;
using std::stoll;
using std::to_string;
#include <queue> // queue priority_queue
using std::queue;
using std::priority_queue;
#include <stack> // stack
using std::stack;
#include <vector> // vector
using std::vector;
#include <map> // map
using std::map;
#include <set> // set
using std::set; // insert erase find count
#include <algorithm> // min max
using std::sort;
using std::lower_bound; // iterator,  >=
using std::upper_bound; // iterator,  >
using std::min;
using std::max;
using std::min_element; // iterator
using std::max_element; // iterator
#include <complex> // complex
using std::complex; // real imag
#include <iostream> // cin cout
using std::cin;
using std::cout;
using std::endl;
#include <iomanip> // setprecision fixed(manipulator)
using std::setprecision;
using std::fixed;
#include <cmath>
#include <cstdio>

#define lli long long int
#define INF (int)1e09
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define EFOR(i, m, n) for (int i = m; i <= n; i++)
#define RFOR(i, m, n) for (int i = m; i > n; i--)
#define REFOR(i, m, n) for (int i = m; i >= n; i--)
#define VSORT(v) sort((v).begin(), (v).end()) // sort vector
typedef pair<int, int> PI;
typedef tuple<int, int, int> TI;
template <typename T> using Vec = vector<T>; // c++11

int main(void) {
    int n;
    int m;
    cin >> n >> m;
    Vec<int> e(m);
    FOR(i, 0, m) {
        cin >> e[i];
    }
    Vec<bool> check(n, true);
    REFOR(i, m - 1, 0) {
        if (check[e[i] - 1] == true) {
            cout << e[i] << endl;
            check[e[i] - 1] = false;
        }
    }
    FOR(i, 0, n) {
        if (check[i] == true) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
