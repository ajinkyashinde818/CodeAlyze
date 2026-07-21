#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

 
const ll INF = 1e12;
const ll N =(2e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
map<int,int> cnt;
int a[N],b[N];
int ans[N];
void solve(){
    int n;
    cin >> n;
    for(int i= 1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i =1;i<=n;i++){
        cin >> b[i];
        cnt[b[i]]++;
    }
    for(auto x:cnt){
        if(x.s > n){
            cout << "No\n";
            return;
        }
    }
    reverse(b+1,b+n+1);
    int l = 1,r = n;
    for(int i = 1;i<=n;i++){
        if(a[i] == b[i]){
            if(a[l] != b[i] && a[i] != b[l]){
                swap(b[l],b[i]);
                l++;
            }
            else{
                swap(b[r],b[i]);
                r--;
            }
        }
    }



    cout << "Yes\n";
    for(int i=1;i<=n;i++){
        cout << b[i] << " ";
    }
    cout << endl;

}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
