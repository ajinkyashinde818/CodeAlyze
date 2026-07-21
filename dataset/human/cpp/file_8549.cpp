#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <cmath>
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007

int main() {
    cin.tie();
    ios::sync_with_stdio(false);

    // input
    int N, M;
    cin >> N >> M;
    vector<string> vec_A(N), vec_B(M);
    REP(i, N) cin >> vec_A.at(i);
    REP(i, M) cin >> vec_B.at(i);
    
    // calculation
    if (N == M) {
        REP(i, N) {
            if (vec_A[i] != vec_B[i]) {
                cout << "No" << "\n";
                return 0;
            }
        }
        cout << "Yes" << "\n";
        return 0;
        
    } else {
        string tmp;
        int sum;
        REP(i, N-M+1) {
            REP(j, N-M+1) {
                sum = 0;
                REP(k, M) {
                    tmp = vec_A[i+k].substr(j, M);
                    if (tmp == vec_B[k]) {
                        sum++;
                    } else {
                        break;
                    }
                }
                
                if (sum == M) {
                    cout << "Yes" << "\n";
                    return 0;
                }
            }
        }
        cout << "No" << "\n";
        
        return 0;
    }
}
