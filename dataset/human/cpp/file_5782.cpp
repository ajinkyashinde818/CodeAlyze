/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int root=0;
const int mx=1e5+5;
struct trie {
    int node[mx][2];
    bool isEnd[mx];
    int nnode;

    trie () {
        nnode=0;
        node[root][0]=node[root][1]=-1;
    }
    void insert (char *str) {
        int i,len,now=0;
        len=strlen(str);
        for (i=0;i<len;i++) {
            if (node[now][str[i]-'0']==-1) {
                node[now][str[i]-'0']=++nnode;
                node[nnode][0]=node[nnode][1]=-1;
            }
            now=node[now][str[i]-'0'];
        }
        isEnd[now]=true;
    }
} T;

ll mxln;
ll grundy (ll n)
{
    ll ans=1;
    for (ans=1;ans<=n;) {
        if (n%ans==0) ans*=2;
        else break;
    }
    return ans/2;
}
ll calc (int pos,int level)
{
    if (T.isEnd[pos]) return 0;
    ll ans1,ans2;
    if (T.node[pos][0]!=-1) ans1=calc(T.node[pos][0],level+1);
    else ans1=grundy(mxln-level);
    if (T.node[pos][1]!=-1) ans2=calc(T.node[pos][1],level+1);
    else ans2=grundy(mxln-level);
    //cout<<ans1<<' '<<ans2<<endl;
    return (ans1^ans2);
}
char str[mx];
int main ()
{
    int i,n;

    scanf ("%d %lld",&n,&mxln);
    for (i=0;i<n;i++) {
        scanf ("%s",str);
        T.insert(str);
    }
    if (calc(0,0)==0) printf ("Bob\n");
    else printf ("Alice\n");

    return 0;
}
