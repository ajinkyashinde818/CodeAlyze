#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
unordered_map<int,int> id;
vector<int> v;
int a[MAXN], b[MAXN];
int p[MAXN], sz[MAXN];
int xa[MAXN], xb[MAXN];
int num = 1,n,N;
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
void unionset(int x, int y){
    x = find(x), y=  find(y);
    if (x == y) return;
    num--;
    p[x] = y;
    sz[y] += sz[x];
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        a[n] ^= a[i];
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&b[i]);
        b[n] ^= b[i];
    }
    for (int i = 0; i <= n; i++){
        xa[i] = a[i], xb[i] = b[i];
    }
    sort(xa,xa+n+1);
    sort(xb,xb+n+1);
    for (int i = 0; i <= n; i++){
        if (xa[i] != xb[i]){
            printf("-1");
            return 0;
        }
    }
    for (int i = 0; i <= n; i++){
        if (a[i] != b[i] || i == n){
            N++;
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for (auto x : v){
        id[x] = num++;
    }
    num--;
    iota(p,p+N,0);
    for (int i = 0; i <= n; i++){
        if (a[i] != b[i] || i == n){
            unionset(id[a[i]],id[b[i]]);
        }
    }
    int ans = N+num-2;
    printf("%d",ans);
}
