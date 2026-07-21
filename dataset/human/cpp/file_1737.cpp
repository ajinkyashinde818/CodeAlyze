#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<random>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde) FUNC(printdu);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int acc = 0;
    int i = 1;
    for(; ; i++){
        acc += i;
        if(acc == n){
            cout << "Yes" << '\n';
            cout << i + 1 << '\n';
            break;
        }else if(acc > n){
            cout << "No" << '\n';
            return 0;
        }
    }
    vector<vector<int>> anss(i + 1, vector<int>(i));
    iota(anss[0].begin(), anss[0].end(), 1);
    int num = i + 1;
    for(int j = 1; j < i + 1; j++){
        for(int k = 0; k < j; k++){
            anss[j][k] = anss[k][j - 1];
        }
        for(int k = j; k < i; k++){
            anss[j][k] = num++;
        }
    }
    printde(anss);
    for(int j = 0; j < i + 1; j++){
        cout << i << ' ';
        for(int k = 0; k < i; k++){
            cout << anss[j][k] << ' ';
        }
        cout << '\n';
    }
}
// 1 2 3, 3 4 5, 5 6 7, 7 1 2, 2 3 4, 4 5 6, 6 7 1
// 1 2 3 4, 3 4 5 6, 5 6 7 8, 7 8 1 2
// 01 10, 10 11, 11 01
// 1, 1
// 1 2, 1 3, 2 3
// 1 2 3, 1 4 5, 2 4 6, 3 5 6
// 1 2 3 4, 1 5 6 7, 2 5 8 9, 3 6 8 10, 4 7 9 10
