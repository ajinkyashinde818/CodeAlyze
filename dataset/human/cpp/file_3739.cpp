#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using ll = long long;
using itn = int;
using namespace std;
int GCD(int a, int b){
    return b ? GCD(b, a%b) : a;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int mnus=0;
    for(int i=0; i<n; i++){
        if(a[i]<0){
            mnus++;
        }
    }
    ll ans=0;
    if(mnus%2){
        int mina=1e9;
        for(int i=0; i<n; i++){
            ans += abs(a[i]);
            if(abs(a[i])<mina){
                mina=abs(a[i]);
            }
        }
        ans = ans - 2*mina;
    }else{
        for(int i=0; i<n; i++){
            ans += abs(a[i]);
        }
    }
    cout << ans << endl;
}
