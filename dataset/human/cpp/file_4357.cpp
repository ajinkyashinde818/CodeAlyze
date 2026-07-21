#include<bits/stdc++.h>
using namespace std;

int N;
int A[100010],B[100010];
vector<int> a,b;
vector<int> cmp;
vector<int> G[100010];
bool F[100010] = {0};
bool visit[100010] = {0};
int ans = 0;

void DFS(int v)
{
    if(visit[v])return;
    visit[v] = true;
    for(int i = 0; i < G[v].size(); i++)DFS(G[v][i]);
    return;
}

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",A + i);
    for(int i = 0; i < N; i++)scanf("%d",B + i);
    int xa = A[0],xb =B[0];
    for(int i = 0; i < N; i++)
    {
        a.push_back(A[i]);
        b.push_back(B[i]);
        cmp.push_back(A[i]);
        cmp.push_back(B[i]);
        if(i != 0)
        {
            xa ^= A[i];
            xb ^= B[i];
        }
    }
    A[N] = xa;
    B[N] = xb;
    a.push_back(xa);
    b.push_back(xb);
    cmp.push_back(xa);
    cmp.push_back(xb);
    sort(cmp.begin(),cmp.end());
    cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 0; i < N + 1; i++)
    {
        if(a[i] != b[i])
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i = 0; i <= N; i++)
    {
        A[i] = lower_bound(cmp.begin(),cmp.end(),A[i]) - cmp.begin() + 1;
        B[i] = lower_bound(cmp.begin(),cmp.end(),B[i]) - cmp.begin() + 1;
    }
    for(int i = 0; i <= N; i++)
    {
        if(A[i] != B[i])
        {
            if(i != N)ans++;
            G[A[i]].push_back(B[i]);
            G[B[i]].push_back(A[i]);
            F[A[i]] = F[B[i]] = true;
        }
    }
    for(int i = 0; i <= N; i++)
    {
        if(!visit[i] && F[i])
        {
            DFS(i);
            ans++;
        }
    }
    printf("%d\n",ans - (F[A[N]]));
    return 0;
}
