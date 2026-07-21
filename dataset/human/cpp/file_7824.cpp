#include <cstdio>
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
 
using namespace std;
using ll = long long;
 
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n) for(int i = n - 1; i >= 0; i--)
#define REP2(i, n, k) for(int i = 0; i < n; i += k)
 
 
int main()
{
    int n, a[200005];
    ll sum = 0, ans, k;
 
    scanf("%d", &n);
    REP(i, n){
        scanf("%d", &a[i]);
 
        sum += a[i];
    }
 
    sum -= a[0];
    k = a[0];
    ans = abs(sum - k);
 
    for(int i = 1; i < n - 1; i++){
        k += a[i];
        sum -= a[i];
 
        ans = min(ans, abs(sum - k));
    }
 
    cout << ans << endl;
}
