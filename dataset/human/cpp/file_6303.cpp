//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

namespace n91 {

  using i8 = std::int_fast8_t;
  using i32 = std::int_fast32_t;
  using i64 = std::int_fast64_t;
  using u8 = std::uint_fast8_t;
  using u32 = std::uint_fast32_t;
  using u64 = std::uint_fast64_t;
  using isize = std::ptrdiff_t;
  using usize = std::size_t;

  constexpr usize operator"" _z(unsigned long long x) noexcept {
    return static_cast<usize>(x);
  }

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
  template <class T> auto md_vec(const usize n, const T& value) {
    return std::vector<T>(n, value);
  }
  template <class... Args> auto md_vec(const usize n, Args... args) {
    return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
  }
  template <class T> constexpr T difference(const T& a, const T& b) {
    return a < b ? b - a : a - b;
  }
  template <class T> T scan() {
    T ret;
    std::cin >> ret;
    return ret;
  }

} // namespace n91

#include <cstdint>

namespace n91 {

  constexpr std::uint_fast64_t totient(std::uint_fast64_t x) noexcept {
    using u64 = std::uint_fast64_t;
    u64 ret = x;
    for (u64 i = static_cast<u64>(2); i * i <= x; ++i) {
      if (x % i == static_cast<u64>(0)) {
        ret -= ret / i;
        x /= i;
        while (x % i == static_cast<u64>(0)) {
          x /= i;
        }
      }
    }
    if (x != static_cast<u64>(1)) {
      ret -= ret / x;
    }
    return ret;
  }

  template <std::uint_fast64_t Modulus,
    std::uint_fast64_t InverseExp =
    totient(Modulus) - static_cast<std::uint_fast64_t>(1)>
    class modint {
    using u64 = std::uint_fast64_t;

    static_assert(Modulus < static_cast<u64>(1) << static_cast<u64>(32),
      "Modulus must be less than 2**32");

    u64 a;

    constexpr modint& negate() noexcept {
      if (a != static_cast<u64>(0)) {
        a = Modulus - a;
      }
      return *this;
    }

    public:
      constexpr modint(const u64 x = static_cast<u64>(0)) noexcept
        : a(x% Modulus) {}
      constexpr u64& value() noexcept { return a; }
      constexpr const u64& value() const noexcept { return a; }
      constexpr modint operator+() const noexcept { return modint(*this); }
      constexpr modint operator-() const noexcept { return modint(*this).negate(); }
      constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
      }
      constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
      }
      constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
      }
      constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
      }
      constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
          a -= Modulus;
        }
        return *this;
      }
      constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
          a += Modulus;
        }
        a -= rhs.a;
        return *this;
      }
      constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
      }
      constexpr modint& operator/=(modint rhs) noexcept {
        u64 exp = InverseExp;
        while (exp) {
          if (exp % static_cast<u64>(2) != static_cast<u64>(0)) {
            *this *= rhs;
          }
          rhs *= rhs;
          exp /= static_cast<u64>(2);
        }
        return *this;
      }
      constexpr bool operator==(const modint rhs) const noexcept {
        return a == rhs.a;
      }
      constexpr bool operator!=(const modint rhs) const noexcept {
        return a != rhs.a;
      }
  };

  template <class T, std::uint_fast64_t v> class modint_constant {
  public:
    static constexpr T value = static_cast<T>(v);

    using value_type = T;
  };

} // namespace n91

#include <algorithm>
#include <iostream>
#include <utility>

namespace n91 {

  void main_() {
    using mint = modint<1000000007>;

    const usize n = scan<usize>();
    std::vector<char> s(n * 2_z);
    for (auto& e : s) {
      std::cin >> e;
    }
    mint ans = static_cast<mint>(1);
    mint count = static_cast<mint>(0);
    bool parity = false;
    for (auto& e : s) {
      if (parity) {
        e ^= 'B' ^ 'W';
      }
      parity = !parity;
      if (e == 'B') {
        count += static_cast<mint>(1);
      }
      else {
        ans *= count;
        count -= static_cast<mint>(1);
      }
    }
    for (const auto i : rep(1_z, n + 1_z)) {
      ans *= static_cast<mint>(i);
    }
    if (count != static_cast<mint>(0)) {
      ans = static_cast<mint>(0);
    }

    std::cout << ans.value() << std::endl;
  }

} // namespace n91

int main() {
  n91::main_();
  return 0;
}
