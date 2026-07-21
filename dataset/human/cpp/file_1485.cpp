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
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "]"; return os; }


int main(){
    LL n;
    cin >> n;
    if(n == 1){
        cout << "Yes" << endl;
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
        return 0;
    }
    LL total = 0;
    for(LL i = 1; i <= n; ++i){
        total += i;
        if(total > n) break;
        if(total == n){
            cout << "Yes" << endl;
            LL c = n * 2 / i;
            cout << c << endl;
            vector<vector<LL> > a(c, vector<LL>(i));
            LL next = 1;
            for(LL j = 0; j < c; ++j){
                cout << i;
                for(LL k = 0; k < j; ++k){
                    a[j][k] = a[k][j-1];
                    cout << " " << a[j][k];
                }
                for(LL k = j; k < i; ++k){
                    a[j][k] = next;
                    cout << " " << a[j][k];
                    next++;
                }
                cout << endl;
            }
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
