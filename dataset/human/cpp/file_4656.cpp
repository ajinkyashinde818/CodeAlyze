#include <cstdint>
#include <iostream>
using i8 = std::int_fast8_t;
using u8 = std::uint_fast8_t;
using i16 = std::int_fast16_t;
using u16 = std::uint_fast16_t;
using i32 = std::int_fast32_t;
using u32 = std::uint_fast32_t;
using i64 = std::int_fast64_t;
using u64 = std::uint_fast64_t;
inline void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
template <class T>
inline void in(T &now) {
    std::cin >> now;
}
template <class T, class... Args>
void in(T &head, Args &... tail) {
    in(head);
    in(tail...);
}
template <class T>
inline void out(T now) {
    std::cout << now;
}
template <class T, class... Args>
void out(T head, Args... tail) {
    out(head);
    out(tail...);
}
template <class T>
inline void up(T &a, const T &b) noexcept {
    if (a < b) {
        a = b;
    }
}
template <class T, class... Args>
void up(T &a, const T &head, const Args &... tail) noexcept {
    up(a, head);
    up(a, tail...);
}
template <class T>
inline void down(T &a, const T &b) noexcept {
    if (b < a) {
        a = b;
    }
}
template <class T, class... Args>
void down(T &a, const T &head, const Args &... tail) noexcept {
    down(a, head);
    down(a, tail...);
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    fast_io();

    i64 n, r;
    in(n, r);
    if (n >= 10) {
        out(r);
    } else {
        out(r + (100 * (10 - n)));
    }

    return 0;
}
