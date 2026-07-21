#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <vector>
#include <set>
#include <regex>
#include <numeric>
#include <boost/format.hpp>

using namespace std;

#define FOR(i, a, b) for (auto i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define DEBUG(_debuged) cerr << #_debuged << ":" << _debuged << endl;

struct L
{
    int t;
    int x;
    int y;
};

vector<int> loadn(int n)
{
    vector<int> v(n);
    REP(i, n)
    cin >> v[i];
    return v;
}

uint64_t modpower(const unsigned int N, const unsigned int K, const unsigned int MOD)
{
    uint64_t ret = 1;
    uint64_t k2 = N;
    REP(i, 31)
    {
        if ((K >> i) & 0x1)
        {
            ret *= k2;
            ret = ret % MOD;
        }
        k2 = (k2 * k2) % MOD;
    }
    return ret;
}

class ModCombinationMemo
{
  public:
    const unsigned int N;
    const unsigned int MOD;
    vector<uint64_t> memo = {1};

    ModCombinationMemo(uint32_t N, uint32_t MOD)
        : N(N), MOD(MOD)
    {
    }

    uint64_t c(uint64_t k)
    {
        if (memo.size() > k)
        {
            return memo[k];
        }

        FOR(i, memo.size(), k + 1)
        {
            const auto number = (memo[i - 1] * (N - i + 1)) % MOD;
            const auto reverceDeon = modpower(i, MOD - 2, MOD);
            memo.push_back(number * reverceDeon % MOD);
        }

        return memo[k];
    }
};

uint64_t c(const unsigned int N, const unsigned int K, const unsigned int MOD)
{
    if (K == 0)
    {
        return 1;
    }

    uint64_t n = 1, k = 1;

    REP(i, K)
    {
        n *= N - i;
        k *= i + 1;

        n = n % MOD;
        k = k % MOD;
    }

    uint64_t powerk = modpower(k, MOD - 2, MOD);

    return (n * powerk) % MOD;
}

unsigned trailing_zeros(unsigned n)
{
    if (!n)
        return -1;
    unsigned int c = 32; // c will be the number of zero bits on the right
    n &= -(signed)n;
    if (n)
        c--;
    if (n & 0x0000FFFF)
        c -= 16;
    if (n & 0x00FF00FF)
        c -= 8;
    if (n & 0x0F0F0F0F)
        c -= 4;
    if (n & 0x33333333)
        c -= 2;
    if (n & 0x55555555)
        c -= 1;
    return c;
}

struct oishisa
{
    int64_t x;
    int64_t y;
    int64_t z;
};

int64_t cint()
{
    int64_t i;
    cin >> i;
    return i;
}

struct Node {
    int left;
    int right;
};


// int main(int argc, char *argv[], char *envp[])
// {
//     const int N(cint());
//     const int M(cint());

//     vector<Node> requests(M);

//     REP(i, M) {
//         cin >> requests[i].left;
//         cin >> requests[i].right;
//     }

//     sort(requests.begin(), requests.end(), [](Node l, Node r){
//         return l.left - r.left < 0 || l.right - l.right < 0;
//     });

//     int required = 0;
//     int next = requests[0].right;
//     REP(i, requests.size()) {
//         const auto& request = requests[i];
//         if (next <= request.left) {
//             required++;
//             next = request.right;
//         }
//         next = min(request.right, next);
//     }

//     required++;

//     cout << required << endl;
// }

// int main(int argc, char *argv[], char *envp[])
// {
//     const int N(cint());
//     long i = 0;

//     REP(k, N) {
//         i += cint() - 1;
//     }
//     cout << i << endl;
// }

// int main(int argc, char *argv[], char *envp[])
// {
//     string s, t;

//     cin >> s >> t;

//     REP(i, t.length()) {
//         if (s == t.substr(i, t.length()) + t.substr(0, i)) {
//             cout << "Yes" << endl;
//             exit(0);
//         }
//     }
//     cout << "No" << endl;
//     exit(0);
// }

// int main(int argc, char *argv[], char *envp[])
// {
//     const uint64_t N(cint());
//     const uint64_t D(cint());


// }

struct IMOD {
    int64_t x = 0;
    int64_t mod = 0;
};

int length(const int64_t c) {
    int i = 0;
    while(c >> i != 0) {
        ++i;
    }
    return i;
}

int popcount(int i) {
     // Java: use >>> instead of >>
     // C or C++: use uint32_t
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) {
    if (v.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << v.front();
    for (auto itr = ++v.begin(); itr != v.end(); itr++) {
        ostr << ", " << *itr;
    }
    ostr << "}";
    return ostr;
}

int main(int argc, char *argv[], char *envp[])
{
    const long R(cint());
    const long G(cint());
    const long B(cint());
    const long N(cint());

    long total = 0;

    REP(r, N / R + 1) {
        REP(g, N / G + 1) {
            if ((N - r * R - g * G) < 0) {
                continue;
            }

            if ((N - r * R - g * G) % B == 0) {
                total ++;
            }
        }
    }

    cout << total << endl;
}
