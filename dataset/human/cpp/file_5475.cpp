#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;
const int kmax = 510000;

long long fact[kmax], fact_inv[kmax], inv[kmax];

int gcd(int a, int b)
{
    if (!b) {
        return a;
    }

    return gcd(b, a % b);
}

void init_comb()
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < kmax; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int r)
{
    if (n < r) {
        return 0;
    }

    if (n < 0 || r < 0) {
        return 0;
    }

    return fact[n] * (fact_inv[r] * fact_inv[n - r] % mod) % mod;
}

template <typename T, T N>
class UnionFind {
    T parent_[N];
    T rank_[N];
    T size_[N];

public:
    UnionFind();
    T Root(T idx);
    bool IsSame(T x, T y);
    void Unite(T x, T y);
    T GetSize(T idx);
};

template <typename T, T N>
UnionFind<T, N>::UnionFind()
{
    for (T i = 0; i < N; i++) {
        parent_[i] = i;
        rank_[i] = 0;
        size_[i] = 1;
    }
}

template <typename T, T N>
T UnionFind<T, N>::Root(T idx)
{
    return parent_[idx] == idx ? idx : parent_[idx] = Root(parent_[idx]);
}

template <typename T, T N>
bool UnionFind<T, N>::IsSame(T x, T y)
{
    return Root(x) == Root(y);
}

template <typename T, T N>
void UnionFind<T, N>::Unite(T x, T y)
{
    x = Root(x);
    y = Root(y);
    if (x == y) {
        return;
    }

    if (rank_[x] < rank_[y]) {
        parent_[x] = y;
        size_[y] += size_[x];
    } else {
        parent_[y] = x;
        size_[x] += size_[y];
        if (rank_[x] == rank_[y]) {
            rank_[x]++;
        }
    }
}

template <typename T, T N>
T UnionFind<T, N>::GetSize(T idx)
{
    return size_[Root(idx)];
}

int main()
{
    int n, r;
    std::cin >> n >> r;

    if (n >= 10) {
        std::cout << r << std::endl;
    } else {
        std::cout << r + 100 * (10 - n) << std::endl;
    }
}
