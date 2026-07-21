#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int main(){
    int n,m = 0; cin >> n;
    vector<int> a(n);
    rep(i,n){
        int prea; cin >> prea;
        if(prea < 0){
            m++;
            prea *= -1;
        }
        a[i] = prea;
    }

    sort(a.begin(),a.end());
  	ll ans = 0;
    if(m % 2 == 1){
        for(int i = 1;i < n; i++){
            ans += a[i];
        }
        ans -= a[0];
    }else{
        rep(i,n) ans += a[i];
    }

    cout << ans << endl;
}
