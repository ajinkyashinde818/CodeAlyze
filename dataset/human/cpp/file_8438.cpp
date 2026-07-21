#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std;
using boost::irange;

template<class T> struct Grid {
    vector<T> data;
    const size_t h, w;
    Grid(size_t h, size_t w, T v = T()) : data(h * w, v), h(h), w(w) {}
    T& operator()(size_t i, size_t j) { return data[i * w + j]; }
    friend istream& operator>>(istream& in, Grid& g) {
        for (auto& v : g.data) in >> v;
        return in;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Grid<char> a(n, n), b(m, m);
    cin >> a >> b;
    for (auto i : irange(0, n - m + 1)) {
        for (auto j : irange(0, n - m + 1)) {
            bool match = true;
            for (auto r : irange(0, m)) {
                for (auto c : irange(0, m)) {
                    if (a(i + r, j + c) != b(r, c)) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}
