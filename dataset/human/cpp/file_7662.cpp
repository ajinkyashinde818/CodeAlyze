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
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    ll sumation=0;
    for(int i=0; i<N; i++){
        cin >> a[i];
        sumation+=a[i];
    }
    ll sum1=a[0], sum2=sumation-sum1;
    ll ans=llabs(sum1-sum2);
    for(int i=1; i<N-1; i++){
        sum1+=a[i];
        sum2-=a[i];
        ll tmp=llabs(sum1-sum2);
        ans=min(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}
