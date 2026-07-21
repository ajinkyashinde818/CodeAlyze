#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    int a[n+10];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ll front[n+10],back[n+10],ans = 1e18;
    front[0] = a[0],back[n-1] = a[n-1];
    for(int i = 1; i < n; i++) front[i] = front[i-1] + a[i];
    for(int i = n-2; i >= 0; i--) back[i] = back[i+1] + a[i];
    for(int i = 0; i < n-1; i++) ans = min(ans,abs(front[i]-back[i+1]));

    cout << ans << endl;

    return 0;
}
