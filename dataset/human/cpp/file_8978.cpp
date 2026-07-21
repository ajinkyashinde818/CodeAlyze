#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

class FMT {
public:
    // P < 2^31
    static constexpr uint32_t N = 1 << 27, W = 137, P = 15 * N + 1;

    FMT() : nx_(n_), ny_(1) {
        data_.resize(n_);
    }
    FMT(int nx, int ny) : nx_(nx), ny_(ny) {
        if ((nx & -nx) != nx || nx < 1 || nx > n_) throw;
        if ((ny & -ny) != ny || ny < 1 || ny > n_) throw;
        data_.resize(nx * ny);
    }

    static void init(int n) {
        if ((n & -n) != n || n < 1 || n > N) throw;

        n_ = n;
        if (n_ < 4) return;

        // Wのべき乗のテーブル
        w_ = (uint32_t *)malloc(n_ * 2 * sizeof *w_);
        w_[0] = 1;
        w_[1] = W;
        for (int n = n_; n < N; n *= 2) {
            w_[1] = mul(w_[1], w_[1]);
        }
        for (int i = 2; i < n_ / 2; i++) {
            w_[i] = mul(w_[i - 1], w_[1]);
        }
        // 各階層ごとに用意
        uint32_t *w = w_, *w1 = w_ + n_ / 2;
        for (int j = n_ / 4; j != 0; j /= 2) {
            for (int i = 0; i < j; i++) {
                *w1 = *w;
                w += 2;
                w1 += 1;
            }
        }
        // 反対側
        const uint32_t r2 = mul(w_[n_ / 4], w_[n_ / 4]);
        w = w_;
        for (int j = n_ / 2; j != 0; j /= 2) {
            w[n_] = 1;
            for (int i = 1; i < j; i++) {
                w[j - i + n_] = mul(w[i], r2);
            }
            w += j;
        }
    }
    static void uninit() {
        free(w_);
    }

    static uint32_t add(uint32_t a1, uint32_t a2) {
        const uint32_t t = a1 + a2;
        return t < P ? t : t - P;
    }
    static uint32_t sub(uint32_t a1, uint32_t a2) {
        const uint32_t t = a1 - a2;
        return t < P ? t : t + P;
    }
    static uint32_t mul(uint32_t a1, uint32_t a2) {
        return (uint64_t)a1 * (uint64_t)a2 % (uint64_t)P;
    }
    static uint32_t inv(uint32_t n) { // nは2冪
        return n == 1 ? 1 : P - P / n;
    }

    uint32_t *data() {
        return &data_[0];
    }
    uint32_t *operator[](size_t y) {
        return &data_[nx_ * y];
    }
    void fmt(int sign) {
        auto f = [&](int n, int s, int m, int k) {
            for (int i = 0; i < k; i++) {
                if (n > 2) {
                    if (sign > 0) {
                        fmt_f(n, s, &data_[m * i], w_ + (n_ - n));
                    } else {
                        fmt_t(n, s, &data_[m * i], w_ + n_ + (n_ - n));
                    }
                } else if (n == 2) {
                    fmt_2(s, &data_[n * i]);
                }
            }
        };
        f(nx_, 1, nx_, ny_);
        f(ny_, nx_, 1, nx_);
    }

private:
    static int n_;
    static uint32_t *w_;
    std::vector<uint32_t> data_;
    int nx_, ny_;

    static void fmt_f(int n, int s, uint32_t *p, uint32_t *w) {
        const int m = n / 2;

        for (int i = 0; i < m; i++) {
            const int j = i + m;
            const uint32_t t0 = add(p[i * s], p[j * s]);
            const uint32_t t1 = mul(p[i * s] - p[j * s] + P, w[i]);
            p[i * s] = t0;
            p[j * s] = t1;
        }

        if (m == 2) {
            fmt_2(s, p);
            fmt_2(s, p + 2 * s);
        } else {
            fmt_f(m, s, p, w + m);
            fmt_f(m, s, p + m * s, w + m);
        }
    }
    static void fmt_t(int n, int s, uint32_t *p, uint32_t *w) {
        const int m = n / 2;

        if (m == 2) {
            fmt_2(s, p);
            fmt_2(s, p + 2 * s);
        } else {
            fmt_t(m, s, p, w + m);
            fmt_t(m, s, p + m * s, w + m);
        }

        for (int i = 0; i < m; i++) {
            int j = i + m;
            const uint32_t t0 = mul(w[i], p[j * s]);
            p[j * s] = sub(p[i * s], t0);
            p[i * s] = add(p[i * s], t0);
        }
    }
    static void fmt_2(int s, uint32_t *p) {
        const uint32_t t0 = add(p[0], p[s]);
        const uint32_t t1 = sub(p[0], p[s]);
        p[0] = t0;
        p[s] = t1;
    }
};

int FMT::n_;
uint32_t *FMT::w_;

int main() {
    int n, m, l;
    cin >> n >> m;
    for (l = 1; l < n; l *= 2);
    FMT::init(l);
    FMT a(l, l), b(l, l);
    string s;
    memset(a.data(), 0, l * l * 4);
    memset(b.data(), 0, l * l * 4);
    for (int y = 0; y < n; y++) {
        cin >> s;
        for (int x = 0; x < n; x++) {
            a[y][x] = s[x] == '#' ? FMT::P - 1 : 1;
        }
    }
    for (int y = 0; y < m; y++) {
        cin >> s;
        for (int x = 0; x < m; x++) {
            b[y == 0 ? 0 : l - y][x == 0 ? 0 : l - x] = s[x] == '#' ? FMT::P - 1 : 1;
        }
    }

    a.fmt(+1);
    b.fmt(+1);
    for (int i = 0; i < l * l; i++) {
        a[0][i] = FMT::mul(a[0][i], b[0][i]);
    }
    a.fmt(-1);

    int k = n - m + 1;
    for (int y = 0; y < k; y++) {
        for (int x = 0; x < k; x++) {
            //uint32_t t = FMT::mul(a[y][x], FMT::inv(l * l));
            //cout << x << " " << y << " " << (int32_t)(t < FMT::P / 2 ? t : t - FMT::P) << endl;
            if (a[y][x] == m * m * l * l) {
                cout << "Yes" << endl;
                quick_exit(0);
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
