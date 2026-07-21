#include "bits/stdc++.h"
// #include <boost/multi_array.hpp>
// #include <boost/optional.hpp>
// #include <boost/range/irange.hpp>
// #include <boost/range/algorithm.hpp>
// #include <boost/range/adaptors.hpp>

// namespace adaptor = boost::adaptors;

using ll = long long;
using i64 = int64_t;

void Main()
{
   int R, G, B, N;
   int r, g, b;
   int ans = 0;
   std::cin >> R >> G >> B >> N;
   for (r = 0; R * r <= N; r++)
   {
      for (g = 0; R * r + G * g <= N; g++)
      {
         if ((N - R * r - G * g) % B == 0)
         {
            ans++;
         }
      }
   }
   std::cout << ans << std::endl;
}

int main()
{
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   Main();
   return 0;
}
