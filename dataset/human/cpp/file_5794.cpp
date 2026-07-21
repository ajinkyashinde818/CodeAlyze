#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using pii = pair<int,int>;
using piii = pair<pii,int>;
using pll = pair<long long, long long>;
using plll = pair<pll, long long>;
// #pragma GCC optimize("Ofast")
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define isSquare(x) (sqrt(x)*sqrt(x) == x)
template<class T>inline bool chmax(T &a, const T &b) {if(a<b){a = b; return 1;} return 0; };
template<class T>inline bool chmin(T &a, const T &b) {if(a>b){a = b; return 1;} return 0; };
inline void in(void){return;}
template <typename First, typename... Rest> void in(First& first, Rest&... rest){cin >> first;in(rest...);return;}
inline void out(void){cout << "\n";return;}
template <typename First, typename... Rest> void out(First first, Rest... rest){cout << first << " ";out(rest...);return;}
const double EPS = 1e-9;
const int mod = 1e9 + 7;
const int INF = 1e9;
const long long INFLL = 1e18;
void iosetup() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
}
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}
template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}
template<class T> vector<T> make_vec(size_t a) {return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S, T>& t){return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S, T>& t){return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class S, class T> pair<S,T> operator*(const pair<S,T> &s, const S& t){return pair<S,T>(s.first*t, s.second*t);}
template <typename T> void Exit(T first){cout << first << endl;exit(0); };
template< int mod > struct ModInt {
    unsigned x; ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator*=(const ModInt &p) {x = (int) (1LL * x * p.x % mod);return *this;}
    ModInt &operator/=(const ModInt &p) {*this *= p.inverse();return *this;}
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); }return ModInt(u);}
    ModInt pow(int64_t n) const {ModInt ret(1), mul(x); while(n > 0) {if(n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x;}
    friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
    static int get_mod() { return mod; }
}; using modint = ModInt< mod >;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const pii dxy[4] = {pii(1,0), pii(0, 1), pii(-1, 0), pii(0, -1)};
bool range(int a, int b, int x){if(a <= x and x < b)return true;else return false;}
bool range(int a, int b, int c, int d, pii p){if(a <= p.first and p.first < b and c <= p.second and p.second < d) return true;else return false;}

template <int char_size, int base>
struct Trie {
    struct Node { // 頂点を
        vector<int> next;    // 子の頂点番号を格納。存在しなければ-1
        vector<int> accept;  // 末端がこの頂点になる文字列の str_id を保存
        int c;               // base からの間隔をint型で表現したもの
        int common;          // いくつの文字列がこの頂点を共有しているか
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };
    vector<Node> nodes;  // trie 木本体
    int root; // 根
    Trie() : root(0) {
        // 初期化。はじめは根しか無い
        nodes.push_back(Node(root));
    }

    void insert(const string &word, int word_id) { // 単語:str と 単語の番号: str_id
    int node_id = 0;
    for (int i = 0; i < (int)word.size(); i++) {
        int c = (int)(word[i] - base);
        int &next_id = nodes[node_id].next[c];
        if (next_id == -1) {  // 次の頂点が存在しなければ追加
            next_id = (int)nodes.size();
            nodes.push_back(Node(c));
        }
        ++nodes[node_id].common;
        node_id = next_id;
    }
    ++nodes[node_id].common;
    nodes[node_id].accept.push_back(word_id); // 単語の終端なので、頂点に番号を入れておく
    }
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }   
};

ll l;
ll grundy;
void dfs(Trie<2, '0'>& trie, int id, int depth = 0){
    // cerr << id << " " << depth << endl;
    auto tno = trie.nodes[id];
    int cnt = 0;
    rep(i, 0, 2){
        if(tno.next[i] != -1) dfs(trie, tno.next[i], depth + 1);
    }
    rep(i, 0, 2)if(tno.next[i] != -1) cnt++;
    if(cnt == 1){
        ll s = 0;
        rep(i, 0, 64){
            if((l - depth)%(1LL << i) != 0){
                s = i - 1;
                break;
            }
        }
        grundy ^= (1LL << s);
    }
}

int main(){
    iosetup();
    ll n; cin >> n >> l;
    Trie<2, '0'> trie;
    rep(i, 0, n){
        string S; cin >> S;
        trie.insert(S);
    }
    grundy = 0;
    dfs(trie, 0);
    if(grundy != 0) puts("Alice");
    else puts("Bob");

    return 0;
}
