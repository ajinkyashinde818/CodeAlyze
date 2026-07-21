#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

typedef long long ll; // -9,223,372,036,854,775,808 から 9,223,372,036,854,775,807

template <class T> using vec = std::vector<T>;
template <class T> using vec2 = vec<vec<T>>;
template <class T> using vec3 = vec<vec<vec<T>>>;

// #define DEBUG
#define B 1
#define W 0

struct GCDResult{long long x; long long y; long long res;};
GCDResult gcd(long long a, long long b){
    if(a < 0){
        auto sub = gcd(-a, b);
        return GCDResult{-sub.x, sub.y, sub.res};
    }
    if(b < 0){
        auto sub = gcd(a, -b);
        return GCDResult{sub.x, -sub.y, sub.res};
    }
    if(a < b){
        auto sub = gcd(b, a);
        return GCDResult{sub.y, sub.x, sub.res};
    }
    // a >= b AND a >= 0 AND b >= 0
    if(b == 0){
        return GCDResult{1LL, 0LL, a};
    }
    // a >= b AND a > 0 AND b > 0
    auto sub = gcd(b, a % b);
    return GCDResult{sub.y, sub.x - sub.y*(a/b), sub.res};
}

// Requires ATC_GCD
const int COM_MAX = 510000;
template <long long p>
class Zp{
    long long content;

    // for comb()
    static array<long long, COM_MAX> fac;
    static array<long long, COM_MAX> finv;
    static array<long long, COM_MAX> inv_;
    static bool is_initialized_com_table;

    // By rng_2 (See https://drken1215.hatenablog.com/entry/2018/06/08/210000)
    // テーブルを作る前処理
    static void COMinit() {
        auto MOD = p;
        auto MAX = COM_MAX;
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv_[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv_[i] = MOD - inv_[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv_[i] % MOD;
        }
        is_initialized_com_table = true;
    }

    // 二項係数計算
    static long long COM(int n, int k){
        auto MOD = p;
        auto MAX = COM_MAX;
        if(!is_initialized_com_table){
            assert(false);
        }
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }



    public:
    Zp(long long content_){
        if(content_ >= 0){
            content = content_ % p;
        }else{
            long long temp = p;
            while(temp < -content_){
                temp *= p;
            }
            content = (temp + content_) % p;
        }
    }

    bool operator==(const Zp<p>& rhs) const{
        return this->content == rhs.content;
    }

    bool operator!=(const Zp<p>& rhs) const{
        return !(*this == rhs);
    }

    Zp<p> operator+(const Zp<p>& rhs) const{
        return Zp<p>(this->content + rhs.content);
    }

    Zp<p> operator-() const{
        return Zp<p>(p - this->content);
    }

    Zp<p> operator-(const Zp<p>& rhs) const{
        return Zp<p>(this->content - rhs.content + p);
    }

    Zp<p> operator*(const Zp<p>& rhs) const{
        return Zp<p>(this->content * rhs.content);
    }

    Zp<p> inv() const{
        if(this->content == 0){
            assert(false);
        }

        auto res = gcd(this->content, p);
        return Zp<p>(res.x);
    }

    Zp<p> operator/(const Zp<p>& rhs) const{
        if(rhs.content == 0){
            assert(false);
        }
        
        return (*this)*rhs.inv();
    }

    Zp<p> pow(int n){
        auto res = Zp<p>(1);
        Zp<p> mult = (*this);
        while(n > 0){
            if(n & 1 == 1){
                res = res*mult;
            }
            n >>= 1;
            mult = mult*mult;
        }
        return res;
    }

    long long raw(){
        return this->content;
    }

    static void initializeCom(){
        COMinit();
    }

    static Zp<p> com(int n, int k){
        return Zp<p>(COM(n, k));
    }

};

template <long long p>
bool Zp<p>::is_initialized_com_table = false;
template <long long p>
array<long long, COM_MAX> Zp<p>::fac;
template <long long p>
array<long long, COM_MAX> Zp<p>::finv;
template <long long p>
array<long long, COM_MAX> Zp<p>::inv_;

Zp<MOD> calcNormalized(ll N, vec<int>& cols){
    int maxLines = N;
    int having = 0;
    Zp<MOD> res(1);
    for(int i=0; i < 2*N; i++){
        auto currentCol = (cols[i] + having)%2;
        // そこの色をかえる必要があるならはじめる
        if(currentCol == B){
            having++;
        }else{
            // 必要がないならおわる。自由度はそのときもってる本数。
            res = res * Zp<MOD>(having);
            having--;
        }
        #ifdef DEBUG
        printf("*START: having\n");
        cout << having << endl << res.raw() << endl;
        printf("*END: having\n");
        #endif
        // もしも終端以外で本数が変なことになったら失敗。
        if(having > maxLines || having < 0){
            return Zp<MOD>(0);
        }
    }
    if(having != 0){
        return Zp<MOD>(0);
    }
    return res;
}

Zp<MOD> perm(ll N){
    if(N == 0){
        return Zp<MOD>(1);
    }
    return Zp<MOD>(N)*perm(N-1);
}


void solve(long long N, std::string S){
    vec<int> cols;
    for(auto iter: S){
        cols.push_back((iter == 'B' ? B : W));
    }

    auto nRes = calcNormalized(N, cols);
    #ifdef DEBUG
    printf("*START: nres\n");
    cout << nRes.raw() << endl;
    printf("*END: nres\n");
    #endif
    auto res = nRes*perm(N);

    cout << res.raw() << endl;
}

// Generated by 1.1.6 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
