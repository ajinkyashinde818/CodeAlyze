#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = (i64)1e9 + 7;

const i64 INF = (i64)1e18 + 7;


template <typename T = i64>
struct Range{
    struct iterator{
        T value;
        const T step, last;
        const T& operator*(){return value;}
        iterator(T value, T step, T last) :
            value(step < static_cast<T>(0) ? max(last, value) : min(last, value)),
            step(step),
            last(last)
        {
        }
        iterator operator++(){value = step < static_cast<T>(0) ? max(value + step, last) : min(value + step, last); return *this;}
        bool operator!=(const iterator& x){return value != x.value;}
    };
    const T start, last, step;

    Range(const T start, const T last, const T step = static_cast<T>(1)) :
        start(start),
        last(last),
        step(step)
    {
    }

    Range(const T last) :
        start(0),
        last(last),
        step(1)
    {
    }

    iterator begin(){return iterator(start, step, last);}
    iterator end(){return iterator(last, step, last);}
};

template <typename F>
struct FixPoint{
    const F _f;
    FixPoint(F&& f) : _f(forward<F>(f)){}

    template<typename... Types>
    decltype(auto) operator()(Types&&... args) const{
        return _f(*this, forward<Types>(args)...);
    }
};

template <typename F>
static decltype(auto) makeRec(F&& f){
    return FixPoint<F>(forward<F>(f));
}

template <typename T, T Value = T()>
vector<T> makeVector(size_t x){
    return vector<T>(x, T(Value));
}

template <typename T, T Value = T(), typename... Types>
auto makeVector(size_t x, Types... args){
    return vector<decltype(makeVector<T, Value>(args...))>(x, makeVector<T, Value>(args...));
}

template <typename T = i64>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template <typename T = i64>
bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

#ifdef TEST
#define dump(x) fprintf(stderr, "line =%4d, name =%7s , ", __LINE__, #x); cout << "value = " << x << endl;
#define vecdump(x) fprintf(stderr, "line =%4d, name =%7s\n", __LINE__, #x); _dump_macro(x);
#else
#define vecdump(x)
#define dump(x)
#endif


void _dump(int, string& x){
#ifdef TEST
    cout << x << endl;
#endif
}

template <typename T>
void _dump(bool, T& x){
#ifdef TEST
    cout << x << " ";
#endif
}

template <typename T, typename U = typename T::iterator>
void _dump(i64, T& x){
#ifdef TEST
    for(auto& elm : x)
        _dump(0, elm);

    cout << endl;
#endif
}

template <typename T>
void _dump_macro(T& x){
    _dump(0, x);
}

void _input(i64, string& x){
    cin >> x;
}

template <typename T>
void _input(bool, T& x){
    cin >> x;
}

template <typename T, typename U = typename T::iterator>
void _input(i64, T& x){

    for(auto& elm : x)
        _input(0, elm);
}

template <typename T>
void input_single(T& x){
    _input(0, x);
}

auto input(){}

template <typename T, typename... Types>
void input(T& value, Types&&... args){
    input_single(value);
    input(forward<Types>(args)...);
};

void _pararell_input(size_t){}

template <typename T, typename... Types>
void _pararell_input(size_t index, T& value, Types&&... args){
    input(value[index]);
    _pararell_input(index, forward<Types>(args)...);
}

template <typename... Types>
void pararell_input(size_t count, Types&&... args){
    for(const auto& i : Range<>(count))
        _pararell_input(i, forward<Types>(args)...);
}


template <i64 mod = MOD>
struct ModInt{
    i64 p;

    ModInt() : p(0){}
    ModInt(i64 x){p = x >= 0 ? x % mod : x + (-x + mod - 1) / mod * mod;}

    ModInt& operator+=(const ModInt& y){p = p + *y - ((p + *y) >= mod ? mod : 0); return *this;}
    ModInt& operator-=(const ModInt& y){p = p - *y + (p - *y < 0 ? mod : 0); return *this;}
    ModInt& operator*=(const ModInt& y){p = (p * *y) % mod; return *this;}
    ModInt& operator%=(const ModInt& y){if(y)p %= *y; return *this;}

    ModInt operator+(const ModInt& y) const{ModInt x = *this; return x += y;}
    ModInt operator-(const ModInt& y) const{ModInt x = *this; return x -= y;}
    ModInt operator*(const ModInt& y) const{ModInt x = *this; return x *= y;}
    ModInt operator%(const ModInt& y) const{ModInt x = *this; return x %= y;}

    friend ostream& operator<<(ostream& stream, const ModInt<mod>& x){
        stream << *x;
        return stream;
    }

    friend ostream& operator>>(ostream& stream, const ModInt<mod>& x){
        stream >> *x;
        return stream;
    }

    ModInt& operator++(){p = (p + 1) % mod; return *this;}
    ModInt& operator--(){p = (p - 1 + mod) % mod; return *this;}

    bool operator==(const ModInt& y) const{return p == *y;}
    bool operator!=(const ModInt& y) const{return p != *y;}

    const i64& operator*() const{return p;}
    i64& operator*(){return p;}

};

using mint = ModInt<>;



i64 solve(i64 _count){

    int n;
    input(n);

    if(!static_cast<bool>(cin))
        return MOD;
#ifdef TEST
    cout << "Case: " << _count << endl;
#endif

    string s;
    input(s);

    auto mpow = [](mint x, i64 y){
        mint z = x;
        mint val = y & 1 ? x : mint(1);
        while(z *= z, y >>= 1)
            if(y & 1)
            val *= z;
        return val;
    };

    auto calc_fact = [mpow]{
        constexpr int N = 3e5;
        vector<mint> fact(N + 1, 1);
        vector<mint> inv(N + 1, 1);
        for(int i = 1; i < N; ++i){
            fact[i + 1] = fact[i] * (i + 1);
            inv[i + 1] = mpow(fact[i + 1], MOD - 2);
        }
        return make_pair(fact, inv);
    };
    vector<mint> fact, inv;
    tie(fact, inv) = calc_fact();


    vector<mint> dp(2 * n + 1, 0);
    dp[0] = 1;
    i64 cnt = 0;
    for(int i = 0; i < 2 * n; ++i){
        if(!cnt && s[i] == 'W'){
            cout << 0 << endl;
            return 0;
        }
        if((cnt & 1) ^ (s[i] == 'W')){
            dp[i + 1] = dp[i] * cnt;
            --cnt;
        }else{
            dp[i + 1] = dp[i];
            ++cnt;
        }
    }

    if(cnt != 0){
        cout << 0 << endl;
        return 0;
    }
    cout << *(dp.back() * fact[n]) << endl;

    return 0;
}


signed main(){

    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t = 0;
    while(solve(++t) != MOD);
}
