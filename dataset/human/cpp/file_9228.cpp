#include <bits/stdc++.h>

#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm/equal.hpp>
#include <boost/range/combine.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;
using namespace boost::algorithm;

main() {
  int64_t n, m;
  cin >> n >> m;

  vector<string> a(n), b(m);
  for (auto&& aa : a) {
    cin >> aa;
  }
  for (auto&& bb : b) {
    cin >> bb;
  }

  for (auto si : irange(0L, n - m + 1)) {
    for (auto sj : irange(0L, n - m + 1)) {
      auto ok = all_of(combine(a | sliced(si, si + m), b), [&](const auto& ab) {
        return boost::equal(boost::get<0>(ab) | sliced(sj, sj + m),
                            boost::get<1>(ab));
      });

      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
