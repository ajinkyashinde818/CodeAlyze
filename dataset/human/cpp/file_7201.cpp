#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    uint N;
    cin >> N;
    vector<ll> as(N, 0);
    for (auto &&i: irange(0U, N)){
        cin >> as.at(i);
    }
    deque<ll> left_sum(N+1,0);
    for (auto &&i: irange(0U, N)){
        left_sum.at(i+1) = left_sum.at(i) + as.at(i);
    }
    left_sum.pop_back();
    left_sum.pop_front();
    ll s{0};
    for (auto &&i: irange(0U, N)){
        s+=as.at(i);
    }
    vector<ll> diff(N-1, 0);
    for (auto &&i: irange(0U, N-1)){
        diff.at(i) = abs(2*left_sum.at(i)-s);
    }
//    for (auto &&i: irange(0U, N-1)){
//        cout << diff.at(i) << " ";
//    }
//    cout << endl;
    sort(diff.begin(), diff.end());
    cout << diff.front();

    return 0;
}
