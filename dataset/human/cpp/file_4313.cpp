#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n,a[maxn],b[maxn],res,tmpa[maxn],tmpb[maxn];
map<int,int> p,been;

int fin(int u) {
    if (p[u]==u) return u;
    return p[u] = fin(p[u]);
}

int main() {
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int sxa=0,sxb=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        tmpa[i] = a[i];
        sxa ^= a[i];
    }
    tmpa[n+1] = sxa;
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        tmpb[i] = b[i];
        sxb^=b[i];
    }
    tmpb[n+1]=sxb;
    sort(tmpa+1,tmpa+n+2);
    sort(tmpb+1,tmpb+n+2);
    for (int i=1;i<=n+1;i++)
        if (tmpb[i]!=tmpa[i]) {
            cout<<-1<<endl;
            return 0;
        }
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]) {
            p[a[i]]=a[i];
            p[b[i]]=b[i];
        }
    for (int i=1;i<=n;i++) res+=(a[i]!=b[i]);
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]) {
            int u = fin(a[i]);
            int v = fin(b[i]);
            if (u!=v) p[u]=v;
        }
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]) {
            res += (been[fin(a[i])]==0);
            been[fin(a[i])]=1;
        }
    bool ok = false;
    for (int i=1;i<=n;i++) ok |= (b[i]==sxa && a[i]!=sxa);
    res-=ok;
    cout<<res<<endl;


}
