#include <cstddef>
#include <complex>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <valarray>
#include <utility>
#include <tuple>
#include <cmath>
#include <memory>
#include <random>
#include <fstream>
#include <locale>
#include <bitset>

using ll = long long;
using ull = unsigned long long;

//vector
template <class T>
using vec = std::vector<T>;

template <class T>
using vvec = vec<vec<T>>;

constexpr std::size_t operator""_sz(ull n) { return std::size_t(n); }

int main()
{
    using namespace std;

    int n;
    cin >> n;

    vec<ll> v(n);
    int minusCount{};
    for (auto &e : v)
    {
        cin >> e;
        if (e < 0)
        {
            minusCount++;
            e *= -1;
        }
    }

    sort(v.begin(), v.end());

    auto sum = accumulate(v.cbegin(), v.cend(), 0ll);

    if (minusCount % 2 == 1)
    {
        sum -= v.front() * 2;
    }

    cout << sum << endl;

    return 0;
}
