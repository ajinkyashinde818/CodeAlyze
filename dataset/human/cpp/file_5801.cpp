#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int Nmax = 1e5 + 5;

string S[Nmax];
int n, i;
ll L, ans = 0;

ll result (ll x)
{
    int i;
    for(i=1; (x & ((1LL<<i) - 1)) == 0 ; ++i);
    return (1LL<<(i-1));
}

class Trie
{
    Trie *left, *right;
    bool used;
    public:
        Trie() { left = right = NULL; used = 0; }

        void add(string &S, int pos)
        {
            if(pos == S.size()) return;

            if(S[pos] == '0')
            {
                if(!left) left = new Trie();
                left -> add(S, pos+1);
            }
            else
            {
                if(!right) right = new Trie();
                right -> add(S, pos+1);
            }
        }

        void solve(string &S, int pos)
        {
            if(pos == S.size()) return;

            if(S[pos] == '0')
            {
                left -> solve(S, pos+1);
                if(!right && !used) ans ^= result(L - pos), used = 1;
            }
            else
            {
                right -> solve(S, pos+1);
                if(!left && !used) ans ^= result(L - pos) , used = 1;
            }
        }

} *root = new Trie();

int main()
{
//    freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n >> L;
    for(i=1; i<=n; ++i)
    {
        cin >> S[i];
        root -> add(S[i], 0);
    }

    ans = 0;
    for(i=1; i<=n; ++i)
        root -> solve(S[i], 0);

    cout << (ans ? "Alice" : "Bob") << '\n';
    return 0;
}
