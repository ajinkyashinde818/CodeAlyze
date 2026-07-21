#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-8;

const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<long long modulus>
class ModInt{
    long long num;

    long long mod(long long n){
        if(n < 0LL){
            n += (abs(n + 1LL) / modulus + 1LL) * modulus;
        }
        return n % modulus;
    }

    long long ext_gcd(long long a, long long b, long long &x, long long &y){
        if(b == 0LL){
            x = 1;
            y = 0;
            return a;
        }

        long long d = ext_gcd(b, a % b, y, x);
        y -= a / b * x;

        return d;
    }

    long long get_inv(long long n){
        long long x, y;
        ext_gcd(n, modulus, x, y);
        return mod(x);
    }

public:
    ModInt(long long n = 0LL){
        init(n);
    }

    void init(long long n = 0LL){
        num = mod(n);
        return;
    }

    long long get(void){
        return num;
    }

    ModInt &operator+=(const ModInt &rhs){
        num += rhs.num;
        if(num >= modulus){
            num -= modulus;
        }
        return *this;
    }

    ModInt &operator-=(const ModInt &rhs){
        num -= rhs.num;
        if(num < 0LL){
            num += modulus;
        }
        return *this;
    }

    ModInt &operator*=(const ModInt &rhs){
        num = num * rhs.num % modulus;
        return *this;
    }

    ModInt &operator/=(const ModInt &rhs){
        long long inv = get_inv(rhs.num);
        num = num * inv % modulus;
        return *this;
    }

    ModInt operator+(const ModInt &rhs) const {
        return ModInt(*this) += rhs;
    }

    ModInt operator-(const ModInt &rhs) const {
        return ModInt(*this) -= rhs;
    }

    ModInt operator*(const ModInt &rhs) const {
        return ModInt(*this) *= rhs;
    }

    ModInt operator/(const ModInt &rhs) const {
        return ModInt(*this) /= rhs;
    }

    ModInt &operator=(const ModInt &rhs){
        num = rhs.num;
        return *this;
    }

    bool operator<(const ModInt &rhs) const {
        return num < rhs.num;
    }
};

template<long long modulus>
istream &operator>>(istream &lhs, ModInt<modulus> &rhs){
    long long val;
    lhs >> val;
    rhs.init(val);
    return lhs;
}

template<long long modulus>
ostream &operator<<(ostream &lhs, ModInt<modulus> rhs){
    lhs << rhs.get();
    return lhs;
}

using mint = ModInt<1000000007LL>;

template<typename T>
bool chmax(T &a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T &a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    lint n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> v(n * 2);
    int l = 0, r = 0;
    rep(i, n * 2){
        int d = l - r;
        if(s[i] == 'W'){
            if(d % 2 == 0){
                ++r;
                v[i] = 0;
            }else{
                ++l;
                v[i] = 1;
            }
        }else if(s[i] == 'B'){
            if(d % 2 == 0){
                ++l;
                v[i] = 1;
            }else{
                ++r;
                v[i] = 0;
            }
        }
    }

    mint ans(1);
    int cnt = 0;
    rep(i, n * 2){
        if(v[i] == 0){
            ans *= mint(cnt);
            --cnt;
        }else{
            ++cnt;
        }
    }

    if(cnt){
        cout << 0 << endl;
        return 0;
    }

    reps(i, n){
        ans *= mint(i);
    }

    cout << ans << endl;

    return 0;
}
