#include <cstddef>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
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


using ll = long long;
using ull = unsigned long long;

//vector
template <class T>
using vec = std::vector<T>;

template <class T>
using vvec = vec<vec<T>>;

constexpr std::size_t operator""_sz(ull n) { return std::size_t(n); }

template <class T, class BinaryOperation>
constexpr T fold(std::initializer_list<T> args, T init, BinaryOperation op)
{
    return std::accumulate(args.begin(), args.end(), init, op);
}

// numeric_low
namespace numeric
{
    // 最大公約数
    template<class T>
    constexpr T gcd(const T x, const T y)
    {
        if (x < 0)return gcd(-x, y);
        if (y < 0)return gcd(x, -y);
        return (!y) ? x : gcd(y, x % y);
    }

    // 最小公倍数
    template<class T>
    constexpr T lcm(const T x, const T y)
    {
        if (x < 0)return lcm(-x, y);
        if (y < 0)return lcm(x, -y);
        return x * (y / gcd(x, y));
    }
}

// argsからハッシュ値を作成
template <class... Args>
std::size_t hash(Args... args)
{
    return fold({ static_cast<std::size_t>(args)... }, 0_sz,
        [](std::size_t seed, std::size_t x)
    {
        // uses magic number from boost
        return seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    });
}

template <class Begin, class End>
void printAll(Begin beginIter, End endIter, std::string delimiter)
{
    for (auto iter{ beginIter }; iter != endIter; ++iter)
    {
        std::cout << *iter;
        if (std::distance(iter, endIter) != 1)
            std::cout << delimiter;
    }
}

template <class Container>
void printAll(const Container& c, std::string delimiter)
{
    printAll(std::cbegin(c), std::cend(c), delimiter);
}

template<class T>
void printAll(const std::initializer_list<T>& ini, std::string delimiter)
{
    printAll(ini.begin(), ini.end(), delimiter);
}


void print(std::vector<int> v)
{
    for (auto e : v)
    {
        std::cout << e << std::endl;
    }

}

int main()
{
    using namespace std;

    int n, m;
    cin >> n >> m;

    vec<int> E(m);

    for (auto& e : E)
        cin >> e;


    vec<int> used(n + 1, -1);

    for (auto e : E)
    {
        used[e]++;
    }
    
    for_each(make_reverse_iterator(E.cend()), make_reverse_iterator(E.cbegin()), [&used](int e)
    {
        if (used[e] >= 0)
        {
            cout << e << endl;
            used[e] = -2;
        }
    });
    

    for (int i = 1; i <=n; ++i)
    {
        if (used[i] == -1)
            cout << i << endl;
    }
    

    return 0;
}
