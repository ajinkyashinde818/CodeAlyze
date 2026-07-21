#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#if __has_include(<optional>)
#include <optional>
#elif __has_include(<experimental/optional>)
#include <experimental/optional>
#endif
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#if __has_include(<variant>)
#include <variant>
#elif __has_include(<experimental/variant>)
#include <experimental/variant>
#endif
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
#include <vector>
// using namespace std;

namespace my_atcoder
{
	constexpr int64_t MOD = 1000000007;

	template <class T>
	class read;

	template <class T, size_t n>
	class read<std::array<T, n>>
	{
	public:
		using ret_type = std::array<T, n>;
		ret_type operator()() const
		{
			ret_type v;
			for (size_t i = 0; i < n; i++) v[i] = read<T>()();
			return v;
		}
	};

	template <class T>
	constexpr std::size_t _tuple_size_v = std::tuple_size<T>::value;
	template <class F, class Tuple, std::size_t... I>
	constexpr decltype(auto) _apply_impl(F&& f, Tuple&& t, std::index_sequence<I...>)
	{
		return std::forward<F>(f)(std::get<I>(std::forward<Tuple>(t))...);
	}
	template <class F, class Tuple>
	constexpr decltype(auto) _apply(F&& f, Tuple&& t)
	{
		return _apply_impl(std::forward<F>(f), std::forward<Tuple>(t),
		                   std::make_index_sequence<_tuple_size_v<std::remove_reference_t<Tuple>>>{});
	}

	template <class... Ts>
	class read<std::tuple<Ts...>>
	{
	public:
		using ret_type = std::tuple<Ts...>;
		ret_type operator()() const
		{
			ret_type v;
			::my_atcoder::_apply([](auto&... args) { (void)std::initializer_list<int>{(void(f(args)), 0)...}; }, v);
			return v;
		}

	private:
		template <class T>
		static int f(T& arg)
		{
			arg = read<T>()();
			return 0;
		}
	};

	template <class T1, class T2>
	class read<std::pair<T1, T2>>
	{
	public:
		using ret_type = std::pair<T1, T2>;
		ret_type operator()() const { return ret_type{read<T1>()(), read<T2>()()}; }
	};

	template <class T, class Allocator>
	class read<std::vector<T, Allocator>>
	{
	public:
		using ret_type = std::vector<T, Allocator>;
		ret_type operator()(size_t len) const
		{
			ret_type v;
			for (size_t i = 0; i < len; i++) v.push_back(read<T>()());
			return v;
		}
	};

	template <class T>
	class read
	{
	public:
		using ret_type = T;
		ret_type operator()() const
		{
			ret_type v;
			std::cin >> v;
			return v;
		}
	};

	template <class T, size_t n>
	std::ostream& operator<<(std::ostream& os, const std::array<T, n>& v)
	{
		auto f = false;
#ifdef MY_RICH_PRINT
		os << "array(";
#endif
		for (auto& e : v)
		{
			if (f)
#ifdef MY_RICH_PRINT
				os << ", ";
#else
				os << " ";
#endif
			os << e;
			f = true;
		}
#ifdef MY_RICH_PRINT
		os << ")";
#endif
		return os;
	}

	template <class T>
	static int my_cout_impl(const T& arg, std::ostream& os, bool& f)
	{
		if (f)
#ifdef MY_RICH_PRINT
			os << ", ";
#else
			os << " ";
#endif
		os << arg;
		f = true;
		return 0;
	}

	template <class... Ts>
	std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& v)
	{
		auto f = false;
#ifdef MY_RICH_PRINT
		os << "tuple(";
#endif
		::my_atcoder::_apply([&os, &f](const auto&... args) { (void)std::initializer_list<int>{(void(my_cout_impl(args, os, f)), 0)...}; },
		                     v);
#ifdef MY_RICH_PRINT
		os << ")";
#endif
		return os;
	}

	template <class T1, class T2>
	std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v)
	{
#ifdef MY_RICH_PRINT
		return os << "pair(" << v.first << ", " << v.second << ")";
#else
		return os << v.first << " " << v.second;
#endif
	}

	template <class T, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::vector<T, Allocator>& v)
	{
		auto f = false;
#ifdef MY_RICH_PRINT
		os << "vector(";
#endif
		for (auto& e : v)
		{
			if (f)
#ifdef MY_RICH_PRINT
				os << ", ";
#else
				os << " ";
#endif
			os << e;
			f = true;
		}
#ifdef MY_RICH_PRINT
		os << ")";
#endif
		return os;
	}

	template <class Key, class T, class Compare, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::map<Key, T, Compare, Allocator>& v)
	{
#ifndef MY_RICH_PRINT
		assert(0);
#endif
		auto f = false;
		os << "map(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p.first << ": " << p.second;
			f = true;
		}
		return os << ")";
	}

	template <class Key, class T, class Compare, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::multimap<Key, T, Compare, Allocator>& v)
	{
#ifndef MY_RICH_PRINT
		assert(0);
#endif
		auto f = false;
		os << "multimap(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p.first << ": " << p.second;
			f = true;
		}
		return os << ")";
	}

	template <class Key, class Compare, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::set<Key, Compare, Allocator>& v)
	{
		auto f = false;
#ifdef MY_RICH_PRINT
		os << "set(";
#endif
		for (auto& p : v)
		{
			if (f)
#ifdef MY_RICH_PRINT
				os << ", ";
#else
				os << " ";
#endif
			os << p;
			f = true;
		}
#ifdef MY_RICH_PRINT
		os << ")";
#endif
		return os;
	}

	template <class Key, class Compare, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::multiset<Key, Compare, Allocator>& v)
	{
		auto f = false;
		os << "multiset(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p;
			f = true;
		}
		return os << ")";
	}

	template <class Key, class T, class Hash, class Pred, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, T, Hash, Pred, Allocator>& v)
	{
#ifndef MY_RICH_PRINT
		assert(0);
#endif
		auto f = false;
		os << "unordered_map(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p.first << ": " << p.second;
			f = true;
		}
		return os << ")";
	}

	template <class Key, class T, class Hash, class Pred, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<Key, T, Hash, Pred, Allocator>& v)
	{
#ifndef MY_RICH_PRINT
		assert(0);
#endif
		auto f = false;
		os << "unordered_multimap(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p.first << ": " << p.second;
			f = true;
		}
		return os << ")";
	}

	template <class Key, class Hash, class Pred, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::unordered_set<Key, Hash, Pred, Allocator>& v)
	{
		auto f = false;
		os << "unordered_set(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p;
			f = true;
		}
		return os << ")";
	}

	template <class Key, class Hash, class Pred, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<Key, Hash, Pred, Allocator>& v)
	{
		auto f = false;
		os << "unordered_multiset(";
		for (auto& p : v)
		{
			if (f) os << ", ";
			os << p;
			f = true;
		}
		return os << ")";
	}

	template <class T, class Container>
	std::ostream& operator<<(std::ostream& os, const std::queue<T, Container>& v)
	{
		std::queue<T, Container> v2 = v;
		auto f = false;
		os << "queue(";
		while (!v2.empty())
		{
			os << (f ? ", " : "front: ") << v2.front();
			v2.pop();
			f = true;
		}
		return os << ")";
	}

	template <class T, class Container>
	std::ostream& operator<<(std::ostream& os, const std::stack<T, Container>& v)
	{
		std::stack<T, Container> v2 = v;
		auto f = false;
		os << "stack(";
		while (!v2.empty())
		{
			os << (f ? ", " : "top: ") << v2.top();
			v2.pop();
			f = true;
		}
		return os << ")";
	}

	template <class T, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::deque<T, Allocator>& v)
	{
		auto f = false;
		os << "deque(";
		for (auto& e : v)
		{
			if (f) os << ", ";
			os << e;
			f = true;
		}
		return os << ")";
	}

	template <class T, class Container, class Compare>
	std::ostream& operator<<(std::ostream& os, const std::priority_queue<T, Container, Compare>& v)
	{
		std::priority_queue<T, Container, Compare> v2 = v;
		auto f = false;
		os << "priority_queue(";
		while (!v2.empty())
		{
			os << (f ? ", " : "top: ") << v2.top();
			v2.pop();
			f = true;
		}
		return os << ")";
	}

	template <class T, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::list<T, Allocator>& v)
	{
		auto f = false;
		os << "list(";
		for (auto& e : v)
		{
			if (f) os << ", ";
			os << e;
			f = true;
		}
		return os << ")";
	}

	template <class T>
	std::ostream& operator<<(std::ostream& os, const std::initializer_list<T>& v)
	{
		auto f = false;
		os << "initializer_list(";
		for (auto& e : v)
		{
			if (f) os << ", ";
			os << e;
			f = true;
		}
		return os << ")";
	}

	template <class T, class Allocator>
	std::ostream& operator<<(std::ostream& os, const std::forward_list<T, Allocator>& v)
	{
		auto f = false;
		os << "forward_list(";
		for (auto& e : v)
		{
			if (f) os << ", ";
			os << e;
			f = true;
		}
		return os << ")";
	}

	// 座圧
	template <class T, class Int = int>
	std::map<T, Int> compress(const std::vector<T>& v)
	{
		std::map<T, Int> m;
		for (auto x : v) m[x] = 0;
		Int n = 0;
		for (auto& t : m) t.second = n++;
		return m;
	}

	// [b, ..., e] must be a shuffle of [0, 1, ..., len - 1] (len = e - b)
	template <class RanIt>
	std::vector<std::vector<typename std::iterator_traits<RanIt>::value_type>> to_cycles(RanIt b, RanIt e)
	{
		using T = typename std::iterator_traits<RanIt>::value_type;
		std::vector<std::vector<T>> cycs;
		T len = e - b;
		std::vector<bool> done(len, false);
		for (T i = 0; i < len; ++i)
		{
			if (done[i]) continue;
			std::vector<T> cyc;
			cyc.push_back(i);
			auto j = b[i];
			while (j != i)
			{
				cyc.push_back(j);
				done[j] = true;
				j = b[j];
			}
			cycs.push_back(std::move(cyc));
		}
		return cycs;
	}

	template <class T>
	auto to_cycles(const T& v)
	{
		return to_cycles(std::begin(v), std::end(v));
	}

	template <class T, size_t n>
	double norm(const std::array<T, n>& p)
	{
		auto s = 0.0;
		for (int i = 0; i < n; ++i) s += double(p[i]) * p[i];
		return std::sqrt(s);
	}
	template <class T, size_t n>
	double dist(const std::array<T, n>& p, const std::array<T, n>& q)
	{
		std::array<T, n> d;
		for (int i = 0; i < n; ++i) d[i] = p[i] - q[i];
		return norm(d);
	}

	template <class Int>
	Int gcd(Int n, Int m)
	{
		while (m > 0)
		{
			Int t = n % m;
			n = m;
			m = t;
		}
		return n;
	}

	template <class Int>
	std::array<Int, 2> solve_linear(Int n, Int m)
	{
		// static_assert(std::is_integral_v<Int> && std::is_signed_v<Int>);
		auto A = std::array<std::array<Int, 2>, 2>{std::array<Int, 2>{n < 0 ? -1 : 1, 0}, std::array<Int, 2>{0, m < 0 ? -1 : 1}};
		if (n < 0) n *= -1;
		if (m < 0) m *= -1;
		while (m > 0)
		{
			Int q = n / m, r = n % m;
			n = m;
			m = r;
			for (int i = 0; i < 2; ++i)
			{
				Int x = A[i][1];
				A[i][1] = A[i][0] - q * x;
				A[i][0] = x;
			}
		}
		return std::array<Int, 2>{A[0][0], A[1][0]};
	}

	template <class Int>
	Int mod(Int a, Int mod)
	{
		// static_assert(std::is_integral_v<Int>);
		return (a % mod + mod) % mod;
	}

	template <class Int>
	Int inverse(Int a, Int M)
	{
		return mod(solve_linear(mod(a, M), M)[0], M);
	}

	template <class Int>
	Int pow(Int a, Int p, Int mod)
	{
		// static_assert(std::is_integral_v<Int>);
		Int y = 1;
		Int x = a;
		while (p > 0)
		{
			if ((p & 1) == 1) y = (y * x) % mod;
			p >>= 1;
			x = (x * x) % mod;
		}
		return y;
	}

	template <class Int, class Pred>
	Int first_binary(Int min, Int max, Pred pred)
	{
		// static_assert(std::is_integral_v<Int>);
		while (min < max)
		{
			Int mid = min + (max - min) / 2;
			if (pred(mid))
				max = mid;
			else
				min = mid + 1;
		}
		return min;
	}

	template <class Int>
	std::vector<Int> get_fact(int max, Int mod)
	{
		std::vector<Int> x{1};
		for (Int i = 1; i <= max; ++i) x.push_back(i * x.back() % mod);
		return x;
	}

	template <class Int>
	std::vector<Int> get_fact_inv(int max, Int mod)
	{
		Int fc = 1;
		for (Int i = 2; i <= max; i++) fc = fc * i % mod;
		std::vector<Int> x(max + 1);
		x[max] = inverse(fc, mod);
		for (Int i = max; i >= 1; --i) x[i - 1] = x[i] * i % mod;
		return x;
	}

	class union_find
	{
		int n_;
		std::unique_ptr<int[]> par_, rk_, sz_;

	public:
		union_find(int cap)
		    : n_(cap), par_(std::make_unique<int[]>(cap)), rk_(std::make_unique<int[]>(cap)), sz_(std::make_unique<int[]>(cap))
		{
			for (int i = 0; i < n_; ++i)
			{
				par_[i] = i;
				rk_[i] = 0;
				sz_[i] = 1;
			}
		}
		int size(int v) { return sz_[root(v)]; }
		int root(int v) { return par_[v] == v ? v : par_[v] = root(par_[v]); }
		bool unite(int u, int v)
		{
			if ((u = root(u)) == (v == root(v))) return false;
			if (rk_[u] < rk_[v])
			{
				par_[u] = v;
				sz_[v] += sz_[u];
			}
			else
			{
				par_[v] = u;
				sz_[u] += sz_[v];
				if (rk_[u] == rk_[v]) ++rk_[u];
			}
			return true;
		}
		bool has_united(int u, int v) { return root(u) == root(v); }
	};

	template <class T>
	bool ch_min(T& x, const T& y)
	{
		if (x > y)
		{
			x = y;
			return true;
		}
		return false;
	}
	template <class T>
	bool ch_max(T& x, const T& y)
	{
		if (x < y)
		{
			x = y;
			return true;
		}
		return false;
	}

	template <class Int = int>
	std::vector<Int> get_primes(Int n)
	{
		if (n < 3) n = 3;
		Int m = (n - 1) >> 1;
		std::vector<Int> ps{2};
		ps.reserve(n / std::log(n));
		std::vector<bool> ok(m, true);
		for (Int i = 0; i < m; ++i)
			if (ok[i])
			{
				Int p = 2 * i + 3;
				ps.push_back(p);
				for (Int k = 3 * i + 3; k < m; k += p) ok[k] = false;
			}
		return ps;
	}

	bool is_prime(uint64_t n)
	{
		if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
		// constexpr auto test = std::array{2, 3, 5, 7, 11, 13, 17, 19, 23, 111};
		auto d = n - 1;
		int s = 0;
		while (d % 2 == 0)
		{
			++s;
			d /= 2;
		}
		auto f = [n, d, s](uint64_t t) {
			auto x = pow(t, d, n);
			if (x == 1) return true;
			for (int r = 0; r < s; ++r)
			{
				if (x == n - 1) return true;
				x = (x * x) % n;
			}
			return false;
		};
		for (auto i : {2, 3, 5, 7, 11, 13, 17, 19, 23})
		{
			if (i >= n) return true;
			if (!f(i)) return false;
		}
		// for (int i = 0; test[i] < n && test[i] != 111; ++i)
		//	if (!f(test[i])) return false;
		return true;
	}

	namespace mp = boost::multiprecision;
	using real = mp::number<mp::cpp_bin_float<200>>;
	using integer = mp::cpp_int;
	using rational = boost::rational<integer>;
	// using std::vector, std::map, std::set, std::string;

	real to_real(const rational& r) { return real(r.numerator()) / real(r.denominator()); }

	void solve()
	{
		auto N = read<int>()();
		auto R = read<int>()();
		int X;
		if (N >= 10)
			X = R;
		else
			X = R + 100 * (10 - N);
		std::cout << X << std::endl;
	}
}  // namespace my_atcoder

int main()
{
	using std::cout;
	using std::endl;
	using std::string;
	using std::vector;
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	my_atcoder::solve();
	cout << std::flush;
	return 0;
}
