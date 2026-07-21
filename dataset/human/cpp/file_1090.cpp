#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;


int main() {
    
    ll ans = 0;
    ll r,g,b,n;
    cin >> r >> g >> b >> n;
    for (ll i=0;i<=n/r;i++){
        for (ll j=0;j<=n/g;j++){
            ll tmp = n - r*i - g*j;
            if(tmp >= 0 and tmp%b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
