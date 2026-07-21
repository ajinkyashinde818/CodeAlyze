#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator> 
#include <limits>

#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define RALL(A) (a).rbegin(),(a).rend()
#define PB push_back
#define MP make_pair

#define dump(x) cerr << #x << " = " << (x) << endl;

using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;


int main(int argc, char const* argv[])
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    LL ans = 0;
    LL now;
    for (int r = 0; r < 3000 + 10; r++) {
        for (int g = 0; g < 3000 + 10; g++) {
            now = N - R * r - G * g;
            if (now >= 0 && now % B == 0) {
                ans += 1;
            }
            if (now < 0) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
