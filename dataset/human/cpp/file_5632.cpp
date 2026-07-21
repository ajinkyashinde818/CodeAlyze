#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int N=1e5+10;
int t[N][2],sz=1;
void add(string s)
{
    int i,cur=0;
    for (i=0;i<s.length();i++)
    {
        if (t[cur][s[i]-'0']==0)
            t[cur][s[i]-'0']=sz++;
        cur=t[cur][s[i]-'0'];
    }
}
long long ans=0,l;
void dfs(int x, int d)
{
    if (bool(t[x][0])!=bool(t[x][1]))
        ans^=(l-d)&(d-l);
    if (t[x][0])
        dfs(t[x][0],d+1);
    if (t[x][1])
        dfs(t[x][1],d+1);
}
int main()
{
    int n,i;
    string s;
    scanf("%d%lld",&n,&l);
    for (i=1;i<=n;i++)
    {
        cin>>s;
        add(s);
    }
    dfs(0,0);
    if (ans)
        printf("Alice\n");
    else
        printf("Bob\n");
    return 0;
}
