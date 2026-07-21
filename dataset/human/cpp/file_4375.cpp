#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int N, A[100005], B[100005], s = 0;
map <int, int> M;
vector <int> V[100005];
int Aux[100005];
set <int> S;

int ind;
bool Use[100005];
int A2[100005], B2[100005];
vector <int> G[100005];
bool check()
{
    sort(A2 + 1, A2 + N + 1);
    sort(B2 + 1, B2 + N + 1);
    for(int i = 1; i <= N; i++)
        if(A2[i] != B2[i])
            return 0;
    return 1;
}
void Read()
{
    cin >> N;
    for(int i = 2; i <= N + 1; i++)
        cin >> A[i], A[1] = (A[1] ^ A[i]);
    for(int i = 2; i <= N + 1; i++)
        cin >> B[i], s = (s ^ B[i]);
    B[1] = s;
    ++N;
    for(int i = 1; i <= N; i++)
    {
        A2[i] = A[i];
        B2[i] = B[i];
        if(M.find(B[i]) == M.end())
        {
            M[B[i]] = ++ind;
        }
        int pos = M[B[i]];
        if(A[i] != B[i] && i > 1)
            V[pos].push_back(i);
    }
    for(int i = 1; i <= ind; i++)
        if(V[i].size() > 0)
            S.insert(i);
    for(int i = 1; i <= N; i++)
    {
        if(M.find(A[i]) != M.end())
        A[i] = M[A[i]];
        B[i] = M[B[i]];
    }
}
void DFS(int node)
{
    Use[node] = 1;
    for(int i = 0; i < G[node].size(); i++)
    {
        int neighb = G[node][i];
        if(Use[neighb] == 0)
            DFS(neighb);
    }
}
void Solve()
{
    int ans = -1;
    int cnt = 0;
    map <int, int> X;
    for(int i = 2 ; i <= N; i++)
        if(A[i] != B[i])
        {
            if(Aux[B[i]] == 0)
            Aux[B[i]] = ++cnt;
            if(Aux[A[i]] == 0)
                Aux[A[i]] = ++cnt;
            G[Aux[B[i]]].push_back(Aux[A[i]]);
            G[Aux[A[i]]].push_back(Aux[B[i]]);
            ++ans;
        }
    if(Aux[A[1]] == 0)
        Aux[A[1]] = ++cnt;
    if(Aux[B[1]] == 0)
        Aux[B[1]] = ++cnt;
    for(int i = 1; i <= cnt; i++)
        if(Use[i] == 0)
        {
            DFS(i);
            ++ans;
        }


    cout << max(ans, 0) << "\n";
}
int main()
{
    Read();
    if(check() == 0)
    {
        cout << "-1\n";
        return 0;
    }
    bool ok = 1;
    for(int i = 1; i <= N; i++)
        if(A[i] != B[i])
            ok = 0;
    if(ok == 1)
    {
        cout << "0\n";
        return 0;
    }
    Solve();
    return 0;
}
