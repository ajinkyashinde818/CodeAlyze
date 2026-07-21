#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<numeric>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(b.rbegin(),b.rend());
    int left = 0;
    int right = n-1;
    rep(i,n){
        if(a[i] == b[i]){
            if((b[left] == b[i] || a[left] == b[i]) && (b[right] == b[i] || a[right] == b[i])){
                cout << "No" << endl;
                return 0;
            }
            if(b[left] != b[i] && a[left] != b[i]){
                swap(b[left],b[i]);
                left++;
            }
            else if(b[right] != b[i] && a[right] != b[i]){
                swap(b[right],b[i]);
                right--;
            }
        }
    }
    cout << "Yes" << endl;
    rep(i,n) cout << b[i] << " ";
    cout << endl;
}
