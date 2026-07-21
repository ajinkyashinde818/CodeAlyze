#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
 
#define rep(i, n) REP(i, 0, n)
#define REP(i, x, n) for(int i = x; i < n; i++)

int N, M;
vector<string> a, b;

// 含まれていたらtrue
bool judge(int start_i, int start_j)
{
    rep(i, M)
    {
        rep(j, M)
        {
            if (a[(start_i + i)][j + start_j] != b[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    string temp;
    cin >> N >> M;
    rep(i, N)
    {
        cin >> temp;
        a.push_back(temp);
    }
    rep(i, M)
    {
        cin >> temp;
        b.push_back(temp);
    }
    
    string res = "No";
    // calc
    rep(i, N - M + 1)
    {
        rep(j, N - M + 1)
        {
            if (judge(i, j)) res = "Yes";
        }
    }
    cout << res << endl;
    return 0;
}
