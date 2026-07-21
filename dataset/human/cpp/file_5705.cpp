#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n;
lli L;
char str[100100];

struct node{
    node *nxt[2];
    int l;
    node () {
        l=0; nxt[0]=nxt[1]=nullptr;
    }
}*root;

void add(node *cur, char *str,int d) {
    if(!(*str)) return;
    int nx=*str - '0';
    if(!cur->nxt[nx]) cur->nxt[nx] = new node(),cur->nxt[nx]->l=d+1;
    add(cur->nxt[nx],str+1,d+1);
}
lli get_least(lli v) {
    lli ret=1;
    while(!(v&1)) v>>=1,ret<<=1;
    return ret;
}
lli dfs(node *cur) {
    int cnt=0;
    lli v=0;
    for(int i=0;i<2;i++) if(cur->nxt[i]) v^=dfs(cur->nxt[i]),cnt++;
    if(cnt==1) {
        v^=get_least(L-cur->l);
    }
    return v;
}

int main() {
    root = new node();
    scanf("%d%lld",&n,&L);
    for(int i=0;i<n;i++) {
        scanf("%s",str);
        add(root,str,0);
    }
    puts(dfs(root) ? "Alice" : "Bob");
    return 0;
}
