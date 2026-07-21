#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    ll ans=0;
    for(int i=0; i+1<n; i+=2){
        ans+=abs(a[i]+a[i+1]);
    }
    if(n%2==1) ans+=a[n-1];
    cout << ans << endl;
    return 0;
}
