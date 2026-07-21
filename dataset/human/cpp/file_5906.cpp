#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "]"; return os; }


// import here

int main(){
    LL n, c;
    cin >> n >> c;
    vector<pair<LL,LL>> sushi(n);
    for(LL i = 0; i < n; ++i){
        cin >> sushi[i].first >> sushi[i].second;
    }
    vector<LL> left_dist(n);
    for(LL i = 0; i < n; ++i){
        left_dist[i] = c - sushi[n-1-i].first;
    }
    vector<LL> left_total(n), right_total(n);
    LL left_sum = 0, right_sum = 0;
    for(LL i = 0; i < n; ++i){
        left_sum += sushi[n-1-i].second;
        left_total[i] = left_sum;
        right_sum += sushi[i].second;
        right_total[i] = right_sum;
    }
    LL ans = 0;
    vector<LL> left_best(n), right_best(n);
    LL best = 0;
    for(LL i = 0; i < n; ++i){
        left_best[i] = best;
        best = max(best, left_total[i] - left_dist[i] * 2);
    }
    best = 0;
    for(LL i = 0; i < n; ++i){
        right_best[i] = best;
        best = max(best, right_total[i] - sushi[i].first * 2);
    }
    for(LL i = 0; i < n; ++i){
        ans = max(ans, left_total[i] - left_dist[i] + right_best[n-1-i]);
        ans = max(ans, right_total[i] - sushi[i].first + left_best[n-1-i]);
    }
    cout << ans << endl;
    return 0;
}
