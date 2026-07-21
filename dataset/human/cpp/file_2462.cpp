#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define Rep(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define Repr(i, b, e) for(int (i) = (b) - 1; (i) >= (e); --(i))
#define Print(x) cout << (x) << endl 
#define Min2(a, b) ((a) < (b)) ? (a) : (b)
#define Max2(a, b) ((a) > (b)) ? (a) : (b)

typedef long long ll;

using namespace std;

int N, A[100000];
ll DP[100000][2];

int main(){
    cin >> N;
    Rep(i, 0, N) cin >> A[i];
    DP[1][0] = A[0] + A[1];
    DP[1][1] = -A[0] - A[1];
    Rep(i, 2, N){
        DP[i][0] = Max2(DP[i - 1][0] + A[i], DP[i - 1][1] + A[i]); 
        DP[i][1] = Max2(DP[i - 1][0] - 2 * A[i - 1] - A[i], DP[i - 1][1] + 2 * A[i - 1] - A[i]); 
    }
    ll m = Max2(DP[N - 1][0], DP[N - 1][1]);
    cout << m << endl;
    return 0;
}
