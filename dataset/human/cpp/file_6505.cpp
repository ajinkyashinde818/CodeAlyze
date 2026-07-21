#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <chrono>
#include <math.h>
using namespace std;

using lli = long long int;
using Vint = std::vector<int>;
using Vlli = std::vector<lli>;
using Wint = std::vector<Vint>;
using Wlli = std::vector<Vlli>;
using Vbool = std::vector<bool>;
using Wbool = std::vector<Vbool>;
using pii = std::pair<int, int>;
using pll = std::pair<lli, lli>;
template <class T>
using Vec = std::vector<T>;
template <class T>
using Wec = Vec<Vec<T>>;

constexpr int MOD = 1e9 + 7;
constexpr int INFi = 2e9 + 1;
constexpr lli INFl = (lli)(9e18) + 1;
const std::vector<std::pair<int, int>> DXDY = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
constexpr char BR = '\n';

#define DEBUG(x) std::cerr << #x << " = " << x << '\n';
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOReq(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); --(i))
#define FORstep(i, a, b, step) for(int (i) = (a); i < (b); i += (step))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) rFOR(i, 0, (n-1))
#define vREP(ele, vec) for(auto &(ele) : (vec))
#define vREPcopy(ele, vec) for(auto (ele) : (vec))
#define SORT(A) std::sort((A).begin(), (A).end())
#define RSORT(A) std::sort((A).rbegin(), (A).rend())
#define ALL(A) (A).begin(), (A).end()
// 座標圧縮 (for vector) : ソートしてから使うのが一般的 ; SORT(A) => COORDINATE_COMPRESSION(A)
#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())


template <class T> inline int argmin(std::vector<T> &vec){return min_element(vec.begin(), vec.end()) - vec.begin();}
template <class T> inline int argmax(std::vector<T> &vec){return max_element(vec.begin(), vec.end()) - vec.begin();}
template <class T> inline T& chmin(T& a, T b){return (a > b) ? a = b : a;}
template <class T> inline T& chmax(T& a, T b){return (a < b) ? a = b : a;}
template <class T> inline void reverseSORT(Vec<T> &Array){
  std::sort(Array.begin(), Array.end(), std::greater<T>());
}
inline int BitI(int k){return 1 << k;}
inline lli BitL(int k){return 1LL << k;}
inline void putsDouble(double d){printf("%.16lf\n", d);}
template <class T> inline std::string toString(T n){
  if(n == 0) return "0";
  std::string res;
  if(n < 0){n = -n;while(n != 0){res += (char)(n % 10 + '0'); n /= 10;}
  std::reverse(res.begin(), res.end()); return '-' + res;}
  while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return res;
}

namespace MyFunc{
    using LLi = long long int;
    using ULLi = unsigned long long int;
    // GCD(a, b) ; a, bの最大公約数を求める関数
    inline LLi gcd(LLi a, LLi b){ while(b != 0){ a %= b; std::swap(a, b);} return a; }
    // LCM(a, b) ; a, bの最小公倍数を求める関数
    inline LLi lcm(LLi a, LLi b){ return (a * b) / MyFunc::gcd(a, b);}
    // 累乗を求める関数
    inline LLi power(LLi a, LLi n){
        LLi res = 1LL, waiting = a;
        while(n != 0LL){ if((n & 1LL) != 0LL) res *= waiting; waiting *= waiting; n >>= 1;}
        return res;
    }
    // 累乗の余りを求める関数
    inline LLi power_mod(LLi a, LLi n, LLi mod_number___ = 1e9 + 7){
        LLi res = 1LL, waiting = a;
        while(n != 0LL){ if((n & 1LL) != 0LL){ res *= waiting; res %= mod_number___;}
            waiting *= waiting; waiting %= mod_number___; n >>= 1; }
        return res;
    }
    // Z/pZ上の逆元を求める関数 (フェルマーの小定理)
    inline LLi inverse_mod(LLi a, LLi mod_number___ = 1e9 + 7){
        return MyFunc::power_mod(a, mod_number___-2);
    }
    inline LLi inverse_mod_euclid(LLi a, LLi mod_number___ = 1e9+7){
        LLi b = mod_number___, u = 1, v = 0;
        while (b != 0) { LLi t = a / b; a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);}
        u %= mod_number___; if (u < 0) u += mod_number___;
        return u;
    }
    // 素数であるかを判定する関数
    template <typename Integer_type>
    inline bool isPrime(Integer_type n){
        if(n < 2) return false; if(n == 2) return true; if(n % 2 == 0) return false;
        for(Integer_type x = 3; x * x <= n; ++++x) if(n % x == 0) return false;
        return true;
    }
    // 素数であるかの真偽表を返す　: n ≥ 1
    inline std::vector<bool> primeTable(int n){
        std::vector<bool> res(n+1, true); res[0] = false; res[1] = false;
        for(int x = 2; x * x <= n; ++x) if(res[x]){
            for(int i = 2 * x; i <= n; i += x){ res[i] = false; } }
        return std::move(res);
    }
    // 素因数分解したベクトルを返す　; {素因数, 指数}
    template <typename Integer_type>
    inline std::vector<std::pair<Integer_type, int>> prime_factorization(Integer_type n){
        std::vector<std::pair<Integer_type, int>> res(0);
        if(n <= 0) return std::move(res); // 例外処理　: nが 0 以下
        if(n % 2 == 0){
            n /= 2; int cnt = 1; while(n % 2 == 0){ n /= 2; cnt++;}
            res.emplace_back(make_pair(2, cnt));
        }
        Integer_type x = 3;
        while(x * x <= n){
            if(n % x == 0){
                n /= x; int cnt = 1; while(n % x == 0){ n /= x; cnt++; }
                res.emplace_back(make_pair(x, cnt));
            } ++++x;
        } if(n > 1) res.emplace_back(make_pair(n, 1));
        return std::move(res);
    }
    // unsigned long 符号なし64bit整数で平方数かを判定する関数 O(log(N))
    inline bool is_square_unsigned(ULLi n){
        // 0 は 平方数
        if(n == 0) return true;
        // 平方数の可能性としては 2^32 - 1 が最大 : (2^32)^2 - 1
        static ULLi MAX_LONG_SQRT__ = (1UL << 32) - 1;
        if(MAX_LONG_SQRT__ * MAX_LONG_SQRT__ < n) return false;
        if(MAX_LONG_SQRT__ * MAX_LONG_SQRT__ == n) return true;
        // 二分探索
        ULLi smaller = 0, bigger = MAX_LONG_SQRT__;
        while(bigger - smaller > 1){
            ULLi m = (smaller + bigger) >> 1;
            if(m * m == n) return true;
            if(m * m < n) smaller = m;
            else bigger = m;
        }
        return false;
    }
    // 符号付き64bit整数で平方数か判定する関数
    inline bool is_square(LLi n){
        if(n < 0) return false;
        // 平方数を4で割った余りは 0 か 1 に限る
        if((n & 0b11) > 0b01) return false;
        return is_square_unsigned(n);
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


std::string S;

int main(void){
    int n; std::cin >> n >> S;
    int N = 2 * n;

    lli res = 1;
    int waiting = 0;
    bool possible = true;
    REP(i, N){
        if(S[i] == 'B'){ // 反転させるべき
            if(waiting % 2 == 0){ // ここから伸ばすべき
                waiting++;
            }
            else{
                (res *= waiting) %= MOD;
                waiting--;
            }
        }
        else{
            if(waiting % 2 == 0){
                if(waiting == 0){
                    possible = false;
                    break;
                }
                (res *= waiting) %= MOD;
                waiting--;
            }
            else{
                waiting++;
            }
        }
    }
    if(waiting != 0) possible = false;

    for(int x = 1; x <= n; x++) (res *= x) %= MOD;

    if(possible) std::cout << res << BR;
    else std::cout << '0' << BR;
    return 0;
}
