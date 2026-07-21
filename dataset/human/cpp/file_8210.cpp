#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;

void solve()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> a(N);
    for (auto& v : a) std::cin >> v;

    std::vector<int64_t> cum(N + 1);
    cum[0] = 0;
    for (int64_t i = 1; i < N + 1; i++)
    {
        cum[i] = cum[i - 1] + a[i - 1];
    }

    int64_t ans = INT64_MAX;
    for (int64_t i = 1; i < N; i++)
    {
        int64_t x = cum[i];
        int64_t y = cum[N] - x;
        ans = std::min<int64_t>(ans, std::abs(x - y));
    }

    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
