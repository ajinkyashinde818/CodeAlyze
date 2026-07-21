#include <bits/stdc++.h>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string/classification.hpp> // is_any_of
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/math/tools/minima.hpp>

const int MOD = 1e9+7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

namespace adaptor = boost::adaptors;
using namespace std;
using boost::math::tools::brent_find_minima;
using boost::irange;
using boost::algorithm::join;
using boost::algorithm::split;
using boost::algorithm::replace_all;
using boost::multiprecision::cpp_int;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int x, y;
	x = n / a;
	y = n / b;
	int cnt;
	cnt = 0;
	for (int i = 0; i <= x; i++)
	{
		if (a * i == n)
		{
			cnt++;
			break ;
		}
		for (int j = 0; j <= y && a * i + b * j <= n; j++)
		{
			if (a * i + b * j == n)
			{
				cnt++;
				break ;
			}
			if ((n - (a * i + b * j)) % c == 0)
				cnt++;
		}
	}
	cout << cnt << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
