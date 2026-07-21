#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int M = 1e5 + 10;
int a[M] , b[M] , ha[M] , hb[M];
bool vis[M] , have[M];
vector<int>vc[M];
void dfs(int u) {
    vis[u] = true;
    int len = vc[u].size();
    for(int i = 0 ; i < len ; i++) {
        int v = vc[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}
int main() {
    int n;
    cin >> n;
    a[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        a[0] ^= a[i];
        ha[i] = a[i];
    }
    ha[0] = a[0];
    b[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        cin >> b[i];
        b[0] ^= b[i];
        hb[i] = b[i];
    }
    hb[0] = b[0];
    sort(ha , ha + n + 1);
    sort(hb , hb + n + 1);
    for(int i = 0 ; i <= n ; i++) {
        if(ha[i] != hb[i]) {
            cout << -1 << endl;
            return 0;
        }//这里是判断能否通过操作得到。
    }
    for(int i = 0 ; i <= n ; i++) {
        a[i] = lower_bound(ha , ha + 1 + n , a[i]) - ha;
        b[i] = lower_bound(hb , hb + 1 + n , b[i]) - hb;
    }//离散一下由于a[i],b[i]太大了。当然用map就不用这样操作了。
    int ans = 0;
    memset(have , false , sizeof(have));
    memset(vis , false , sizeof(vis));
    for(int i = 0 ; i <= n ; i++) {
        if(a[i] != b[i] || i == 0) {
            if(i) ans++;
            have[a[i]] = true , have[b[i]] = true;
            vc[a[i]].push_back(b[i]);
        }
    }
    for(int i = 0 ; i <= n ; i++) {
        if(!vis[i] && have[i]) {
            dfs(i) , ans++;
        }
    }
    ans--;//这里的ans--是减去第0位点被算进去的情况
    ans = max(ans , 0);
    cout << ans << endl;
    return 0;
}
