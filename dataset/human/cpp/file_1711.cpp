#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back

typedef long long LL; 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N; cin >> N;

    //vector<int> possibleN;
    int count = 1;
    bool possible = 0;
    while(1)
    {
        int tmp = count * (count + 1);
        if(tmp > 1e6) break;
        if(tmp == 2 * N) 
        {
            possible = 1;
            break;
        }
        count++;
    }

    if(possible)
    {
        cout << "Yes" << endl;
        cout << count+1 << endl;
        vector<vector<int>> ans(count+1, vector<int>(count, 0));
        int start = 0;
        int startnum = 1;
        dump(count)

        REP(i,count)
        {
            int tmpstartnum1 = startnum;
            int tmpstartnum2 = startnum;
            REP(j,count-i)
            {
                dump(start)
                dump(start+j)
                dump(tmpstartnum1)
                ans[start][start+j] = tmpstartnum1++;
            }
            REP(j,count-i)
            {
                dump(start+1+j)
                dump(start)
                dump(tmpstartnum2)
                ans[start+1+j][start] = tmpstartnum2++;
            }
            start++;
            startnum += count - i;
        }

        REP(i,count+1)
        {
            cout << count << " ";
            REP(j,count)
            {
                if(j != count-1)
                    cout << ans[i][j] << " ";
                else
                    cout << ans[i][j] << endl;
            }

        }

    }
    else
    {
        cout << "No" << endl;
    }


}
