#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>
 
#define lint long long
#define VI vector<int>
#define VL vector<lint>
#define VB vector<bool>
#define VC vector<char>
#define VS vector<string>
#define VVI vector<VI>
#define VVL vector<VL>
#define rep(i, n) for(int i = 0 ; i < n ; i++)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    VS a(n), b(m);
    rep(i, n){
        cin >> a[i];
    }
    rep(i, m){
        cin >> b[i];
    }
    bool ans;
    rep(i, n-m+1){
        rep(j, n-m+1){
            ans = true;
            rep(k, m){
                if(b[k] != a[j+k].substr(i, m)){
                    ans = false;
                    break;
                }
            }
            if(ans){
                break;
            }
        }
        if(ans){
            break;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
