#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <tuple>

#define INF 100100100100
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

 
int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    ll sum = 0;
    ll mina = INF;
    ll count = 0;
    bool zero = false;
    rep(i,n){
        if(a[i] == 0){
            zero = true;
        }
        if(a[i] < 0){
            count++;
        }
        
        sum += abs(a[i]);
        mina = min(mina, abs(a[i]));
        
    }
    
    if(zero){
        cout << sum << endl;
        return 0;
    }
    if(count %2 == 0){
        cout << sum << endl;
        return 0;
    }
    cout << sum - 2*mina<< endl;
    
    
}
