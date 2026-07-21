#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char newl = '\n';

constexpr double ticks_per_sec = 3000000000; // AtCoder: 3000000000;
constexpr double ticks_per_sec_inv = 1.0 / ticks_per_sec;
inline double rdtsc() { // in seconds
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return (((uint64_t)hi << 32) | lo) * ticks_per_sec_inv;
}
constexpr double TLE = 2; // sec
constexpr double time_limit = TLE * 0.93;

unsigned int randxor()
{
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

template<typename hoge>
void my_shuffle(vector<hoge>& v) {
    int sz = v.size();
    for (int i = sz - 1; i >= 1; i--) {
        swap(v[i], v[randxor() % (i + 1)]);
    }
}

int main() {
    double begin_time = rdtsc();
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int pena = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (n == 1) {
        if (a[0] == b[0]) cout << "No\n";
        else {
            cout << "Yes\n";
            cout << b[0] << newl;
        }
        return 0;
    }

    my_shuffle(b);
    for (int i = 0; i < n; i++) {
        pena += (a[i] == b[i]);
    }
    
    while (rdtsc() - begin_time < time_limit && pena > 0) {
        int i1 = randxor() % n;
        int i2 = randxor() % (n - 1);
        i2 += (i2 >= i1);

        int nex_pena = pena - (a[i1] == b[i1]) + (a[i1] == b[i2]) - (a[i2] == b[i2]) + (a[i2] == b[i1]);
        if (nex_pena < pena) {
            swap(b[i1], b[i2]);
            pena = nex_pena;
        }
    }

    if (pena > 0) {
        vector<int> cntb(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ++cntb[b[i]];
        }
    
        map<int, int> buf;
        vector<int> ans;
        ans.reserve(n);
        for (int i = 1; i <= n && ans.size() < n; i++) {
            if (!cntb[i]) continue;
    
            while (ans.size() < n && cntb[i]) {
                if (a[ans.size()] == i) {
                    buf[-i] = cntb[i];
                    break;
                }
                ans.push_back(i);
                --cntb[i];
            }
        }
    
        while (ans.size() < n) {
            bool f = false;
            for (auto& p : buf) {
                if (-p.first == a[ans.size()]) continue;
                ans.push_back(-p.first);
                f = true;
                break;
            }
    
            if (f) {
                if (--buf[-ans.back()] == 0) buf.erase(-ans.back());
                continue;
            }
    
            cout << "No\n";
            return 0;
        } 
    
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i + 1 == n];
        }
    } else {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
