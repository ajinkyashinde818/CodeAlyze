#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int n;
string s;
int cnt, cst;
const ll mod = 1000000007;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 1;
    cin >> n >> s;
    for(char ch : s)
    {
        if((cnt % 2 == 0) == (ch == 'B'))
        {
            cnt++;
        }
        else
        {
            ans = ans * cnt % mod;
            cnt--;
            if(cnt < 0) break;
        }
    }
    if(cnt){
        cout << 0;
    }
    else
    {
        for(int i=1;i<=s.length()/2;i++)
        {
            ans = i * ans % mod;
        }
        cout << ans;
    }
}
