//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <vector>

namespace n91 {

	using i8 = std::int_least8_t;
	using i32 = std::int_least32_t;
	using i64 = std::int_least64_t;
	using u8 = std::uint_least8_t;
	using u32 = std::uint_least32_t;
	using u64 = std::uint_least64_t;
	using isize = std::ptrdiff_t;
	using usize = std::size_t;

	class rep {
		const usize f, l;

	public:
		class itr {
			friend rep;
			usize i;
			constexpr itr(const usize x) noexcept : i(x) {}

		public:
			void operator++() noexcept { ++i; }
			constexpr usize operator*() const noexcept { return i; }
			constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
		};
		constexpr rep(const usize first, const usize last) noexcept
			: f(first), l(last) {}
		constexpr itr begin() const noexcept { return itr(f); }
		constexpr itr end() const noexcept { return itr(l); }
	};
	class revrep {
		const usize f, l;

	public:
		class itr {
			friend revrep;
			usize i;
			constexpr itr(usize x) noexcept : i(x) {}

		public:
			void operator++() noexcept { --i; }
			constexpr usize operator*() const noexcept { return i; }
			constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
		};
		constexpr revrep(usize first, usize last) noexcept : f(--first), l(--last) {}
		constexpr itr begin() const noexcept { return itr(l); }
		constexpr itr end() const noexcept { return itr(f); }
	};
	template <class T> using vec_alias = std::vector<T>;
	template <class T> auto md_vec(const usize n, const T &value) {
		return std::vector<T>(n, value);
	}
	template <class... Args> auto md_vec(const usize n, Args... args) {
		return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
	}
	template <class T> constexpr T difference(const T &a, const T &b) {
		return a < b ? b - a : a - b;
	}

} // namespace n91

#include <cassert>
#include <cstdint>

template <::std::uint_least32_t Modulus> class modint {
	using u32 = ::std::uint_least32_t;
	using u64 = ::std::uint_least64_t;
	using i64 = ::std::int_fast64_t;
	class optimize_tag_t {};
	static constexpr optimize_tag_t optimize_tag{};

public:
	using value_type = u32;
	value_type a;

private:
	static constexpr value_type cst(i64 x) noexcept {
		x %= static_cast<i64>(Modulus);
		if (x < static_cast<i64>(0)) {
			x += static_cast<i64>(Modulus);
		}
		return static_cast<value_type>(x);
	}

	constexpr modint(optimize_tag_t, const value_type &x) noexcept : a(x) {}

public:
	constexpr modint() noexcept : a(static_cast<value_type>(0)) {}
	constexpr modint(const i64 &x) noexcept : a(cst(x)) {}
	constexpr value_type value() const noexcept { return a; }
	constexpr modint operator+(const modint &o) const noexcept {
		return modint(optimize_tag,
			a + o.a < Modulus ? a + o.a : a + o.a - Modulus);
	}
	constexpr modint operator-(const modint &o) const noexcept {
		return modint(optimize_tag, a < o.a ? a + Modulus - o.a : a - o.a);
	}
	constexpr modint operator*(const modint &o) const noexcept {
		return modint(
			optimize_tag,
			static_cast<value_type>(static_cast<u64>(a) * static_cast<u64>(o.a) %
				static_cast<u64>(Modulus)));
	}
	constexpr modint operator/(const modint &o) const {
		return modint(
			optimize_tag,
			static_cast<value_type>(static_cast<u64>(a) * static_cast<u64>((~o).a) %
				static_cast<u64>(Modulus)));
	}
	modint &operator+=(const modint &o) noexcept {
		if ((a += o.a) >= Modulus)
			a -= Modulus;
		return *this;
	}
	modint &operator-=(const modint &o) noexcept {
		if (a < o.a)
			a += Modulus;
		a -= o.a;
		return *this;
	}
	modint &operator*=(const modint &o) noexcept {
		a = static_cast<value_type>(static_cast<u64>(a) * static_cast<u64>(o.a) %
			static_cast<u64>(Modulus));
		return *this;
	}
	modint &operator/=(const modint &o) {
		a = static_cast<u64>(a) * (~o).a % Modulus;
		return *this;
	}
	constexpr modint inverse() const noexcept {
		assert(a != static_cast<value_type>(0) && "0 does not have inverse");
		return pow(static_cast<u64>(Modulus - static_cast<value_type>(2)));
	}
	constexpr modint operator~() const noexcept { return inverse(); }
	constexpr modint operator-() const noexcept {
		if (a == static_cast<value_type>(0)) {
			return modint(optimize_tag, static_cast<value_type>(0));
		}
		else {
			return modint(optimize_tag, Modulus - a);
		}
	}
	modint &operator++() noexcept {
		if (++a == Modulus) {
			a = static_cast<value_type>(0);
		}
		return *this;
	}
	modint &operator--() noexcept {
		if (a == static_cast<value_type>(0)) {
			a = Modulus;
		}
		--a;
		return *this;
	}
	constexpr bool operator==(const modint &o) const noexcept { return a == o.a; }
	constexpr bool operator!=(const modint &o) const noexcept { return a != o.a; }
	constexpr bool operator<(const modint &o) const noexcept { return a < o.a; }
	constexpr bool operator<=(const modint &o) const noexcept { return a <= o.a; }
	constexpr bool operator>(const modint &o) const noexcept { return a > o.a; }
	constexpr bool operator>=(const modint &o) const noexcept { return a >= o.a; }
	constexpr explicit operator bool() const noexcept { return a; }
	constexpr explicit operator value_type() const noexcept { return a; }
	modint pow(u64 x) const noexcept {
		u64 t = a, u = 1;
		while (x) {
			if (x & 1)
				u = u * t % Modulus;
			t = (t * t) % Modulus;
			x >>= 1;
		}
		return modint(optimize_tag, static_cast<value_type>(u));
	}
};


#include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include<array>

namespace n91 {

	void main_() {
		using mint = modint<1000000007>;
		usize n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		std::array<usize, 26> count = {};
		for (const auto c : s) {
			++count[c - 'a'];
		}
		mint ans = 1;
		for (const auto e : count) {
			if (e != 0) {
				ans *= mint(e + 1);
			}
		}
		std::cout << (ans-1).a << std::endl;
	}

} // namespace n91

int main() {
	n91::main_();
	return 0;
}
