#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef long long ll;

int N;
ll L;
int cnt = 1;
int T[200010][2];

ll unit(int v,int d)
{
    ll x = L - d + 1;
    if(v == 0 && d != 0)return x & -x;
    return unit(T[v][0],d + 1) ^ unit(T[v][1],d + 1);
}

int main()
{
    scanf("%d%lld",&N,&L);
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int nxt = 0;
        for(int j = 0; j < s.size(); j++)
        {
            int w = s[j] - '0';
            if(T[nxt][w] == 0)T[nxt][w] = cnt++;
            nxt = T[nxt][w];
        }
    }
    if(unit(0,0))printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
