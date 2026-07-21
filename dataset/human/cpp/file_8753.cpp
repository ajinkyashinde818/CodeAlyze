#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
#include <stdlib.h>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    for (ll i=0;i<n;++i){
        cin >> a[i];
    }
    for (ll i=0;i<m;++i){
        cin >> b[i];
    }
    for (ll i=0;i<n-m+1;++i){
        for (ll j=0;j<n-m+1;++j){
            bool flag=true;
            for (ll k=i;k-i<m;++k){
                for (ll l=j;l-j<m;++l){
                    if (a[k][l]!=b[k-i][l-j]){
                        flag=false;
                    }
                }
            }
            if (flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
