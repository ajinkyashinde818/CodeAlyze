#include<iostream>
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

#include<boost/multi_array.hpp>
#include<boost/variant.hpp>
#include<boost/optional.hpp>
#include<boost/optional/optional_io.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

#include<cstdlib>
#include<ctime>

namespace lib
{
	using namespace boost::range;
	template<std::uint64_t Mod>struct modnum;
	template<class T>constexpr T pow(T base, std::size_t p)
	{
		if (p == 0)
		{
			return T(1);
		}
		else if (p == 1)
		{
			return base;
		}
		else if (p == 2)
		{
			return base * base;
		}
		else if (p % 2 == 0)
		{
			return pow(pow(base, p / 2), 2);
		}
		else
		{
			return pow(pow(base, p / 2), 2)*base;
		}
	}
	template<std::uint64_t Mod>constexpr auto inverse(modnum<Mod> const&);

	template<std::uint64_t Mod>struct modnum
	{
		static constexpr auto mod = Mod;
		std::uint64_t val;
		modnum() = default;
		constexpr modnum(std::uint64_t v):val(v%Mod)
		{

		}

		constexpr modnum& operator+=(modnum const& v)
		{
			val += v.val;
			val %= mod;
			return *this;
		}
		constexpr modnum& operator-=(modnum const& v)
		{
			val += mod - v.val;
			val %= mod;
			return *this;
		}
		constexpr modnum& operator*=(modnum const& v)
		{
			val *= v.val;
			val %= mod;
			return *this;
		}
		constexpr modnum& operator/=(modnum const& v)
		{
			return operator*=(inverse(v));
		}
	};
	template<std::uint64_t Mod>constexpr auto operator+(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs += rhs;
	}
	template<std::uint64_t Mod>constexpr auto operator-(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs -= rhs;
	}
	template<std::uint64_t Mod>constexpr auto operator*(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs *= rhs;
	}
	template<std::uint64_t Mod>constexpr auto operator/(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs /= rhs;
	}

	template<std::uint64_t Mod>constexpr auto inverse(modnum<Mod>const& base)
	{
		return pow(base, Mod - 2);
	}

	template<class T>constexpr auto clamp(T v)
	{
		return std::max(v, T());
	}

	template<int val>using int_tag = std::integral_constant<int, val>;

	template<class Return, class Argument>struct minimam_searcher
	{
		Return operator()(std::function<Return(Argument)> func, Argument beg, Argument end)const
		{
			Return min = std::numeric_limits<Return>::max();
			for (; beg != end; ++beg)
			{
				min = std::min(min, func(beg));
			}
			return min;
		}
	};
	template<class Return, class Argument>constexpr minimam_searcher<Return, Argument> minimam{};

	template<class T>T gcd(T a, T b)
	{
		if (a > b)
		{
			return gcd(b, a);
		}
		if (a == T())
		{
			return b;
		}
		return gcd(b%a, a);
	}

	static constexpr std::int64_t intlog2(std::int64_t x)
	{
		for (std::int64_t i = 0, j = 2; i < 64; ++i, j <<= 1)
		{
			if (j > x)
			{
				return i;
			}
		}
		return 64;
	}

	struct segtree
	{
		std::vector<std::int64_t> tree;
		std::size_t depth_;
		segtree(std::size_t depth):tree(std::size_t(1) << (depth + 1)), depth_(depth)
		{

		}

		void change(std::size_t index, std::int64_t val)
		{
			change(index, val, 0);
		}

		std::int64_t get(std::size_t left, std::size_t right)//[left, right]の範囲
		{
			return get(left, right + 1, 0, 1, 0);
		}

		void increment(std::size_t index)
		{
			increment(index, 0);
		}

		void decrement(std::size_t index)
		{
			decrement(index, 0);
		}
	private:
		std::int64_t change(std::size_t index, std::int64_t val, std::size_t dep)
		{
			auto shift = std::size_t(1) << dep;
			auto s = std::size_t(1) << (depth_ - dep);
			if (dep == depth_)
			{
				std::swap(tree[shift + index / s - 1], val);
				return val;
			}
			else
			{
				auto v = change(index, val, dep + 1);
				tree[shift + index / s - 1] += val - v;
				return v;
			}
		}

		std::int64_t get(std::size_t a, std::size_t b, std::size_t left, std::size_t right, std::size_t dep)
		{
			auto lshift = left << (depth_ - dep);
			auto rshift = right << (depth_ - dep);
			if (a <= lshift && rshift <= b)
			{
				return tree[(std::size_t(1) << dep) + left - 1];
			}
			else if (rshift <= a || b <= lshift)
			{
				return 0;
			}
			else
			{
				return
					get(a, b, left << 1, left + right, dep + 1) +
					get(a, b, left + right, right << 1, dep + 1);
			}
		}

		void increment(std::size_t index, std::size_t dep)
		{
			auto shift = std::size_t(1) << dep;
			auto s = std::size_t(1) << (depth_ - dep);
			++tree[shift + index / s - 1];
			if (dep != depth_)
			{
				increment(index, dep + 1);
			}
		}

		void decrement(std::size_t index, std::size_t dep)
		{
			auto shift = std::size_t(1) << dep;
			auto s = std::size_t(1) << (depth_ - dep);
			--tree[shift + index / s - 1];
			if (dep != depth_)
			{
				decrement(index, dep + 1);
			}
		}
	};
	template<class T, int N>class binary_indexed_tree
	{
		std::array<T, N> ar;
	public:
		binary_indexed_tree(T val = 0)//全ての要素をvalで初期化する
			:ar{}
		{
			for (int i = 1; i <= N; ++i)
			{
				ar[i - 1] = (i&-i)*val;
			}
		}
		void add(T val, int index)//index番の要素にvalを足す
		{
			++index;
			for (; index <= N; index += index & -index)
			{
				ar[index - 1] += val;
			}
		}
		T get(int index)const//0からindex番までの要素の和を返す
		{
			T ret{};
			for (++index; index > 0; index -= index & -index)
			{
				ret += ar[index - 1];
			}
			return ret;
		}
	};

	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

	template<class T>auto max(std::vector<T>const& vec)
	{
		return *std::max_element(vec.begin(), vec.end());
	}
	template<class T>auto min(std::vector<T>const& vec)
	{
		return *std::min_element(vec.begin(), vec.end());
	}

	struct union_find_light
	{
		std::vector<int> upper;
		union_find_light(std::size_t size):upper(size, -1)
		{

		}

		int group(int index)
		{
			if (upper[index] == -1)
			{
				return index;
			}
			else
			{
				auto ret = group(upper[index]);
				upper[index] = ret;
				return ret;
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

		std::map<int, std::set<int>> get()
		{
			std::map<int, std::set<int>> ret;
			for (int i = 0; i < upper.size(); ++i)
			{
				ret[group(i)].emplace(i);
			}
			return ret;
		}
	};

	template<class T, class Selector>void orderby(std::vector<T>& vec, Selector select)
	{
		lib::sort(vec, [=](T const& lhs, T const& rhs) {return select(lhs) < select(rhs); });
	}

	template<class T, class... Ts>auto make_array(T const& val, Ts const&... vals)
	{
		return std::array<T, sizeof...(Ts)+1>{val, vals...};
	}


	template<class Selector>auto make_compare(Selector selector)
	{
		return [=](auto const& lhs, auto const& rhs) {return selector(lhs) < selector(rhs); };
	}

	template<class Iterator>auto make_range(Iterator first, Iterator last)
	{
		struct return_type
		{
			Iterator first;
			Iterator last;
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

	auto irange(std::int64_t first, std::int64_t last)
	{
		return boost::irange(first, last);
	}

	template<class T>auto get_factorial_array(std::size_t size)
	{
		std::vector<T> ret(size + 1);
		ret[0] = 1;
		for (std::size_t i = 1; i <= size; ++i)
		{
			ret[i] = ret[i - 1] * T(i);
		}
		return ret;
	}

	template<class Range>void write_range(Range const& range)
	{
		int i = 0;
		for (auto const& r : range)
		{
			if (i++ != 0)
			{
				std::cout << " ";
			}
			std::cout << r;
		}
		std::cout << std::endl;
	}

	template<class Range, class Selector>void write_range(Range const& range, Selector select)
	{
		int i = 0;
		for (auto const& r : range)
		{
			if (i++ != 0)
			{
				std::cout << " ";
			}
			std::cout << select(r);
		}
		std::cout << std::endl;
	}

	template<class T>void write_range(std::initializer_list<T>const& range)
	{
		write_range<std::initializer_list<T>>(range);
	}

	template<class T>void write_line(T const& v)
	{
		std::cout << v << std::endl;
	}

	template<class T0, class T1, class... Ts>void write_line(T0 const& v0, T1 const& v1, Ts const&... vs)
	{
		std::cout << v0 << " ";
		write_line(v1, vs...);
	}

	struct randomizer
	{
		std::mt19937_64 random;
		randomizer():random()
		{
			std::random_device device{};
			std::array<unsigned, 623> init;
			for (auto& v : init)
			{
				v = device();
			}
			std::seed_seq seq(init.begin(), init.end());
			random = std::mt19937_64(seq);
		}

		std::int64_t operator()()
		{
			return random();
		}

		std::int64_t operator()(std::int64_t max)//[0, max]の範囲
		{
			std::uniform_int_distribution<std::int64_t> dist(0, max);
			return dist(random);
		}

		std::int64_t operator()(std::int64_t min, std::int64_t max)//[min, max]の範囲
		{
			std::uniform_int_distribution<std::int64_t> dist(min, max);
			return dist(random);
		}
	};
}

namespace std
{
	template<std::uint64_t Mod>decltype(auto) operator<<(ostream& ost, lib::modnum<Mod>const& v)
	{
		return ost << v.val;
	}
}

namespace adaptor = boost::adaptors;

void Main();
int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	std::cout << std::fixed;
	Main();
}

typedef lib::modnum<1000000007> mod_t;

void Main()
{
	int N;
	std::int64_t C;
	std::cin >> N >> C;
	typedef std::pair<std::int64_t, std::int64_t>type;
	std::vector<type> normal(N);
	std::vector<type> reverse(N);
	for (int i = 0; i < N; ++i)
	{
		std::int64_t x, v;
		std::cin >> x >> v;
		normal[i] = std::make_pair(x, v);
		reverse[N - i - 1] = std::make_pair(C - x, v);
	}
	std::vector<type> ndata(N + 1);
	std::vector<type> rdata(N + 1);
	{
		ndata[0] = std::make_pair(0, 0);
		rdata[0] = std::make_pair(0, 0);
	}
	ndata[1].first = normal[0].second - normal[0].first;
	rdata[1].first = reverse[0].second - reverse[0].first;
	ndata[1].second = std::max(ndata[1].first, ndata[0].second);
	rdata[1].second = std::max(rdata[1].first, rdata[0].second);

	for (int i = 2; i <= N; ++i)
	{
		ndata[i].first = ndata[i - 1].first + normal[i - 1].second - (normal[i - 1].first - normal[i - 2].first);
		rdata[i].first = rdata[i - 1].first + reverse[i - 1].second - (reverse[i - 1].first - reverse[i - 2].first);
		ndata[i].second = std::max(ndata[i].first, ndata[i - 1].second);
		rdata[i].second = std::max(rdata[i].first, rdata[i - 1].second);
	}
	std::int64_t max = 0;
	for (int i = 1; i <= N; ++i)
	{
		max = std::max(max, ndata[i].first);
		max = std::max(max, rdata[i].first);
		max = std::max(max, ndata[i].first - normal[i - 1].first + rdata[N - i].second);
		max = std::max(max, rdata[i].first - reverse[i - 1].first + ndata[N - i].second);
	}
	max = std::max(max, ndata[N].first);
	max = std::max(max, rdata[N].first);
	lib::write_line(max);
}
