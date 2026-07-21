#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>

#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
#include<boost/range/size.hpp>
#include<boost/coroutine2/coroutine.hpp>
#undef max
#undef min

#ifdef _MSC_FULL_VER
#include"randomizer.hpp"
#endif

#include<cstdlib>
#include<ctime>

#define DEFINE_STRUCT2(arg0,arg1,stc)\
auto const& arg0=std::get<0>(stc);\
auto const& arg1=std::get<1>(stc)

#define DEFINE_STRUCT3(arg0,arg1,arg2,stc)\
DEFINE_STRUCT2(arg0,arg1,stc);\
auto const& arg2=std::get<2>(stc)

namespace lib
{
	template<class T>using pair = std::pair<T, T>;
	template<class T>constexpr T pow(T base, std::size_t p)
	{
		if (p <= 2)
		{
			return
				p == 0 ? T(1) :
				p == 1 ? base : base * base;
		}
		auto r = lib::pow(lib::pow(base, p / 2), 2);
		if (p % 2 != 0)
		{
			r *= base;
		}
		return r;
	}

	template<class T>constexpr T gcd(T a, T b)
	{
		return a > b ? gcd(b, a) : a == T() ? b : gcd(b%a, a);
	}
	template<class T>constexpr T lcm(T a, T b)
	{
		auto g = gcd(a, b);
		return (a / g)*b;
	}

	constexpr int intlog2(std::int64_t x)
	{
		if (x == 0)
		{
			return 0;
		}
		int c = 0;
		while (x != 0)
		{
			x /= 2;
			++c;
		}
		return c - 1;
	}

	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

	struct union_find_light
	{
		std::vector<int> upper;
		union_find_light(std::size_t size):upper(size, -1) {}

		int group(int index)
		{
			if (upper[index] == -1)
			{
				return index;
			}
			else
			{
				return upper[index] = group(upper[index]);
			}
		}

		bool merge(int x, int y)
		{
			auto gx = group(x);
			auto gy = group(y);
			if (gx != gy)
			{
				upper[gx] = gy;
				return true;
			}
			return false;
		}

		auto get()
		{
			std::map<int, std::set<int>> ret;
			for (int i = 0; i < upper.size(); ++i)
			{
				ret[group(i)].emplace(i);
			}
			return ret;
		}

		auto tops()
		{
			std::set<int> ret;
			for (int i = 0; i < upper.size(); ++i)
			{
				ret.emplace(group(i));
			}
			return ret;
		}

		bool is_same_group(int x, int y)
		{
			return group(x) == group(y);
		}
	};

	template<class Selector>auto make_compare(Selector select)
	{
		return [=](auto const& lhs, auto const& rhs) {return select(lhs) < select(rhs); };
	}

	template<class Iterator>auto make_range(Iterator first, Iterator last)
	{
		struct return_type
		{
			Iterator first, last;
			auto begin()const
			{
				return first;
			}
			auto end()const
			{
				return last;
			}
		};
		return return_type{ first, last };
	}

	template<class T>auto factorial_array(std::size_t max)
	{
		std::vector<T> ret(max + 1);
		ret[0] = 1;
		for (auto i : boost::irange<std::size_t>(1, max + 1))
		{
			ret[i] = ret[i - 1] * T(i);
		}
		return ret;
	}

	auto const first = [](auto p) {return p.first; };
	auto const second = [](auto p) {return p.second; };

	auto maxf = [](auto a, auto b) {return std::max(a, b); };
	auto minf = [](auto a, auto b) {return std::min(a, b); };

	template<class T>using dual_array = boost::multi_array<T, 2>;
	template<class T>using optional_dual_array = boost::multi_array<boost::optional<T>, 2>;
	template<class T>constexpr T min_value = std::numeric_limits<T>::min();
	template<class T>constexpr T max_value = std::numeric_limits<T>::max();
}

namespace out
{
	namespace detail
	{
		template<class>struct void_out
		{
			typedef void type;
		};

		template<class T>auto write(std::ostream& ost, T const& val)
			->typename void_out<decltype(ost << val)>::type
		{
			ost << val;
		}
		template<class T, class... Ts>void write(std::ostream& ost, T const& val, Ts const&... nexts)
		{
			write(ost, val);
			ost << " ";
			write(ost, nexts...);
		}
		template<class T, std::size_t... Is>void write_tuple(std::ostream& ost, T const& tuple, std::index_sequence<Is...>)
		{
			write(ost, std::get<Is>(tuple)...);
		}
		template<class... Ts>void write(std::ostream& ost, std::tuple<Ts...>const& tuple)
		{
			write_tuple(ost, tuple, std::make_index_sequence<sizeof...(Ts)>());
		}
		template<class T, class U>void write(std::ostream& ost, std::pair<T, U>const& pair)
		{
			write(ost, pair.first, pair.second);
		}
		template<class T>void write(std::ostream& ost, boost::optional<T>const& opt)
		{
			if (opt)
			{
				write(ost, *opt);
			}
			else
			{
				write(ost, "--");
			}
		}
		template<class T>auto write(std::ostream& ost, std::vector<T> const& vec)
		{
			for (auto const& v : vec)
			{
				write(ost, v);
				ost << " ";
			}
		}
	}
	void write_line()
	{
		std::cout << std::endl;
	}
	template<class...Ts>void write_line(Ts const&... args)
	{
		detail::write(std::cout, args...);
		write_line();
	}
	template<class Range>void write_range(Range const& rng)
	{
		for (auto const& v : rng)
		{
			write_line(v);
		}
	}
}

namespace in
{
	template<class T>auto read(T& v)
		->typename out::detail::void_out<decltype(std::cin >> v)>::type
	{
		std::cin >> v;
	}
	template<class T, class U>void read(std::pair<T, U>& p)
	{
		read(p.first);
		read(p.second);
	}
	template<class T>std::vector<T> read_vector(std::size_t N)
	{
		std::vector<T> vec(N);
		for (auto& v : vec)
		{
			read(v);
		}
		return vec;
	}
}

namespace adaptor = boost::adaptors;

void Main()
{
	int N;
	in::read(N);
	auto N2 = 2 * N;
	auto k = 1;
	while (true)
	{
		if (k*(k - 1) > N2)
		{
			out::write_line("No");
			return;
		}
		else if (k*(k - 1) == N2)
		{
			break;
		}
		else
		{
			++k;
		}
	}
	lib::dual_array<int> ar(boost::extents[k][k - 1]);
	out::write_line("Yes");
	int start = 0;
	for (int i : boost::irange(0, k - 1))
	{
		for (int j : boost::irange(i, k - 1))
		{
			ar[i][j] = start + (j - i);
			ar[j + 1][i] = start + (j - i);
		}
		start += k - 1 - i;
	}
	out::write_line(k);
	for (int i : boost::irange(0, k))
	{
		std::cout << k - 1 << " ";
		for (int j : boost::irange(0, k - 1))
		{
			std::cout << ar[i][j] + 1 << " ";
		}
		out::write_line();
	}
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
