#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll c=0, c_0=0, ans=0, m=10000000000;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]<0){
            c++;
            a[i]=-a[i];
            m=min(m, a[i]);
        }else if(a[i]==0){
            c_0++;
        }else{
            m=min(m, a[i]);
        }
        ans+=a[i];
    }
    if((c+c_0)%2==0){
        cout << ans;
    }else{
        if(c_0>0){
            cout << ans;
        }else{
            cout << ans-2*m;
        }
    }

    
    return 0;
}
