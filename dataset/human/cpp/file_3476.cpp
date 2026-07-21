#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn], n;
bool judge()
{
    int tot = 0;
    for(int i = 1; i <= n; i++)if(a[i] < 0)
    {
        int cnt = 0, j = i;
        for(; j <= n; j++)if(a[j] < 0)cnt++;else break;
        if(cnt&1)tot++;
        i = j - 1;
    }
    return tot&1;
}
int main()
{
    int flag = 0, minn = 1e9 + 7;
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];sum += abs(a[i]);
        minn = min(minn, abs(a[i]));
        if(!a[i])flag = 1;
    }
    if(flag)cout<<sum<<endl;
    else
    {
        if(judge())cout<<sum - 2 * minn<<endl;
        else cout<<sum<<endl;
    }
	return 0;
}
