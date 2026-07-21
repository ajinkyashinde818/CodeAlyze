#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
LL gi () {
    LL ret=0; char ch=getchar();
    while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    char c=ch=='-'?getchar():ch;
    while(c>='0' && c<='9') ret=ret*10+c-'0',c=getchar();
    return ch=='-'?-ret:ret;
}
const int N = 100000 + 10;
int n;
LL f[N],g[N],v[N],x[N],y[N],C;
struct node {
    int x; LL v;
};
bool operator < (const node &x, const node &y) {
    return x.v < y.v;
}
priority_queue<node> q;
int main () {
    n = gi(); C = gi();
    for(int i=1;i<=n;i+=1) x[i] = gi(), v[i] = gi(), y[i] = C-x[i];
    LL ans = 0;
    for(int i=1;i<=n;i+=1) f[i] = f[i-1] - (x[i] - x[i-1]) + v[i], ans = max(ans, f[i]);
    for(int i=n;i>=1;i-=1) g[i] = g[i+1] - (y[i] - y[i+1]) + v[i], ans = max(ans, g[i]), q.push((node){i,g[i]});
    for(int i=1;i<=n;i+=1) {
        while(!q.empty() && q.top().x <= i) q.pop();
        if(q.empty()) break;
        int t = q.top().x;
        ans = max(ans, f[i] + g[t] - x[i]);
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i+=1) q.push((node){i,f[i]});
    for(int i=n;i>=1;i-=1) {
        while(!q.empty() && q.top().x >= i) q.pop();
        if(q.empty()) break;
        int t = q.top().x;
        ans = max(ans, f[t] + g[i] - y[i]);
    }
    cout << ans;
    return 0;
}
