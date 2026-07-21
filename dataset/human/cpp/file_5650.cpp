#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n,cur;
long long m;
int h[maxn], child[maxn][2], bad[maxn];
char s[maxn];

int get(int x,int y) {
    if(child[x][y]==-1) {
        cur++;
        h[cur] = h[x]+1;
        child[x][y] = cur;
    }
    return child[x][y];
}

long long G(long long x) {
    long long ans = 1;
    while(x%2==0) x/=2, ans*=2;
    return ans;
}

int main() {
    int i,x,t,len;
    long long ans = 0;

    cur = 0;
    h[cur] = 0;
    memset(child,-1,sizeof(child));

    scanf("%d%lld",&n,&m);
    for(t=0;t<n;t++) {
        scanf(" %s",s);
        len = strlen(s);
        for(i=0,x=0;i<len;i++) x = get(x,s[i]-'0');
    }

    for(i=0;i<=cur;i++) {
        if((child[i][0]==-1 && child[i][1]!=-1) || (child[i][0]!=-1 && child[i][1]==-1)) {
            ans ^= G(m-h[i]);
        }
    }

    if(ans==0) printf("Bob");
    else printf("Alice");
}
