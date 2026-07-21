#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>

void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ std::cin >> head; _cin(std::forward<Tail>(tail)...); }
void _cout(){ std::cout << "\n"; } template <class Head, class... Tail> void _cout(Head&& head, Tail&&... tail){ std::cout << head; _cout(std::forward<Tail>(tail)...); }
int gcd(int a, int b){ return (b == 0) ? a : gcd(b, a % b); }

#define For(i, n) for(int i = 0; i < (n); i ++)
#define Rep(n) For(_, n)
#define Range(c) c.begin(), c.end()
#define RevRange(c) c.rbegin(), c.rend()
#define Contains(c, x) (find(Range(c), x) != c.end())
#define Sort(a) sort(Range(a))
#define DeSort(a) sort(RevRange(a))
#define Vec2(T, n, m, xs) vector<vector<T>> xs(n, vector<T>(m))
#define Sum(a) accumulate(Range(a), 0)
#define Cusum(T, n, xs, sxs) vector<T> sxs(n+1); For(i, n) sxs[i+1] = sxs[i] + xs[i]
#define Cin(T, ...) T __VA_ARGS__; _cin(__VA_ARGS__)
#define Cins(T, n, xs) vector<T> xs(n); For(i, n) cin >> xs[i]
#define Cins2(T, n, xs, ys) vector<T> xs(n), ys(n); For(i, n) cin >> xs[i] >> ys[i]
#define Cins3(T, n, xs, ys, zs) vector<T> xs(n), ys(n), zs(n); For(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cinss(T, n, m, xs) Vec2(T, n, m, xs); For(i, n) For(j, m) cin >> xs[i][j]
#define Cinm(T, n, map) unordered_map<T, int> map; Rep(n){ Cin(T, x); map[x] ++; }
#define Cout(...) _cout(__VA_ARGS__)
#define Couts(xs) for(const auto &e : xs) cout << e << " "; cout << "\n"
#define Coutyn(cond) Cout((cond) ? "yes" : "no")
#define CoutYn(cond) Cout((cond) ? "Yes" : "No")
#define CoutYN(cond) Cout((cond) ? "YES" : "NO")

constexpr int MOD = 1e9+7;

using namespace std;
using ll = long long;

int main(void){
    Cin(int, n, m);
    Cinss(char, n, n, a);
    Cinss(char, m, m, b);
    
    For(i, n-m+1) For(j, n-m+1){
        if([a, b, m, i, j](){
            For(x, m) For(y, m){
                if(a[i+x][j+y] != b[x][y]) return false;
            }
            return true;
        }()){
            Cout("Yes");
            return 0;
        }
    }
    Cout("No");
}
