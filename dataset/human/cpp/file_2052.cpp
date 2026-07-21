#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
int n, a[maxn];
int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    LL sum = 0;
    int cnt = 0;
    int mn = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x < 0){
            cnt++;
            x = -x;
        }
        sum += x;
        mn = min(x, mn);
    }
    if(cnt & 1){
        sum -= mn*2;
    }
    cout << sum << endl;
    return 0;
}
