#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,k=1,tr[N][2];
ll l;
char s[N];
ll lowbit(ll x){return x&(-x);}
ll dfs(int x,int t){
    if(x==0)return lowbit(l-t+1);
    return dfs(tr[x][0],t+1)^dfs(tr[x][1],t+1);
}
int main(){
    scanf("%d%lld",&n,&l);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int p=1;
        for(int j=1;s[j];j++){
            if(tr[p][s[j]-'0']==0)tr[p][s[j]-'0']=++k;
            p=tr[p][s[j]-'0'];
        }
    }
    if(dfs(1,0)==0)puts("Bob");
    else puts("Alice");
    return 0;
}
