#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#define debug(x) cerr << #x << ':' << x << endl
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    vector<int> nums;
    REP(k,n+1) nums.push_back(k*c);
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0; j<=n; j++){
            int res = n-(i*a+j*b);
            if(binary_search(ALL(nums), res)){
            // cout << i<< " "<<j << endl;
                ans++;
            //  cout << "res:"<<res << endl;
            // cout << "ans:"<<ans << endl;    
            }

            
        }
    }
    cout << ans << endl;
    return 0;
}
