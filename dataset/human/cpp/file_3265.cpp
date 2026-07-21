#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <functional>
#include <bitset>
#include <queue>

#include <boost/range/irange.hpp>
using boost::irange;

#include <boost/utility/string_ref.hpp>
using string_view = boost::string_ref;

#include <boost/function_output_iterator.hpp>

using namespace std;

template<class T>
constexpr T gcd(T m, T n)
{
    return n == 0 ? (m < 0 ? -m : m) : gcd(n, m % n);
}


int main()
{
    int n;;
    cin >> n;
    vector<int> as(n);
    for(auto& a : as) cin >> a;
    
    uint64_t minabs = abs(as[0]);
    uint64_t abssum = 0;
    int count_minus = 0;
    for(int a : as)
    {
        if(a < 0)
        {
            ++count_minus;
            a = -a;
        }
        abssum += a;
        minabs = min(minabs, (uint64_t)a);
    }
    if(count_minus % 2 == 0)
    {
        cout << abssum << '\n';
    }
    else
    {
        cout << (abssum - minabs * 2) << '\n';
    }
    return 0;
}
