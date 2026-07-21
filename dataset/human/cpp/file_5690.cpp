#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0, l;
string s;

struct STrie
{
    STrie *bit[2];

    STrie() { bit[0] = bit[1] = nullptr; }
} *rt = new STrie();

void add(string &s)
{
    STrie *cur = rt;
    for (char &c : s)
    {
        int b = c - '0';
        if (cur->bit[b] == nullptr)
            cur->bit[b] = new STrie();
        cur = cur->bit[b];
    }
}

void DFS(STrie *cur, int dep)
{
    int cnt = (cur->bit[0] == nullptr) + (cur->bit[1] == nullptr);
    if (cnt == 1)
        ans ^= (1LL << (__builtin_ctzll(l - dep)));
    if (cur->bit[0] != nullptr)
        DFS(cur->bit[0], dep + 1);
    if (cur->bit[1] != nullptr)
        DFS(cur->bit[1], dep + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    while (n--)
    {
        cin >> s;
        add(s);
    }
    DFS(rt, 0);
    cout << (ans ? "Alice" : "Bob");
}
