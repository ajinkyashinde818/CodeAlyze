#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    int N;
    cin >> N;

    vll As(N);
    rep(i, N) {
        cin >> As[i];
    }
    ll min = std::abs(As[0]);
    // int minIndex = 0;
    ll sum = 0;

    int count = 0;
    rep(i, N) {
        if (As[i] <= 0) count++;
        sum += std::abs(As[i]);
        // cout << sum << endl;
        min = std::min(min, std::abs(As[i]));
    }

    // rep(i, N-1) {
    //     if (As[i] <= 0) {
    //         As[i] *= -1;
    //         As[i+1] *= -1;
            
    //         min = std::min(min, As[i]);
    //     }
    //     sum += As[i];
    // }

    // if (As[N-1] >= 0) {
    //     sum += As[N-1];
    // } else {
    //     if (min < -As[N-1]) {
    //         // cout << sum << endl;
    //         sum = sum - min - min - As[N-1];
    //     } else {
    //         sum += As[N-1];
    //     }
    // }
    cout << ((count % 2 == 0) ? sum : sum - 2*min) << endl;
}
