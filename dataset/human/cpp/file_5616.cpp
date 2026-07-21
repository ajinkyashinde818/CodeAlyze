#include <bits/stdc++.h>

#include <boost/algorithm/string/classification.hpp>  // is_any_of
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/math/tools/minima.hpp>
#include <boost/multi_array.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/optional.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>

#define rep(i, n) for (int i = 0; i < (n); ++i)

namespace adaptor = boost::adaptors;
using namespace std;
using boost::irange;
using boost::algorithm::join;
using boost::algorithm::replace_all;
using boost::algorithm::split;
using boost::math::tools::brent_find_minima;
using boost::multiprecision::cpp_int;
using ll = long long;
using P = pair<int, int>;

// TOP
void Main()
{
	int n, r;
	cin >> n >> r;
	if (n < 10)
		r += 100 * (10 - n);
	cout << r << endl;
}
// END

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
