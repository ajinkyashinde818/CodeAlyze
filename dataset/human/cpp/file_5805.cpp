#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, p;
ll l;
int lc[100100], rc[100100];
bool ed[100100];

char buf[100100];

void con(int cur, int i) {
    if (!buf[i]) {
        ed[cur] = 1;
        return;
    }
    int *xc = ((buf[i]=='0')?lc:rc);
    if (xc[cur]<0) {
        xc[cur]=p;
        lc[p]=rc[p]=-1;
        p++;
    }
    con(xc[cur],i+1);
}

ll c;
void dfs(int cur, ll d=0) {
    if (ed[cur]) return;
    if (~lc[cur]) dfs(lc[cur],d+1);
    else c^=(l-d)&(d-l);
    if (~rc[cur]) dfs(rc[cur],d+1);
    else c^=(l-d)&(d-l);
}

int main() {
    int i, j;

    scanf("%d%lld",&n,&l);
    lc[0]=rc[0]=-1;p=1;
    for (i=0;i<n;i++) {
        scanf("%s",buf);
        con(0,0);
    }
    dfs(0);
    puts(c?"Alice":"Bob");

    return 0;
}
