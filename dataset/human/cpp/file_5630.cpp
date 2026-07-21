#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll L;
vector<string> S;
vector<vector<int> > trie;
vector<int> term, dep;
vector<ll> hi;

void dfs(int u) {
    if(!term[u] && trie[u][0] == -1) hi.push_back(L - dep[u] - 1);
    if(!term[u] && trie[u][1] == -1) hi.push_back(L - dep[u] - 1);
    if(trie[u][0] != -1) dfs(trie[u][0]);
    if(trie[u][1] != -1) dfs(trie[u][1]);
}

int grundy[100];

void Grundy() {
    grundy[0] = 1;

    for(int i = 1; i < 100; i++) {
        vector<int> chk(1000, 0);

        chk[0] = 1;
        int Xor = 0;
        for(int j = i - 1; j >= 0; j--) {
            Xor ^= grundy[j];
            chk[Xor] = 1;
        }

        for(int j = 0; j < 1000; j++) if(!chk[j]) {
            grundy[i] = j;
            break;
        }

        cout << i << ' ' << grundy[i] << endl;
    }
}

int main() {
    scanf("%d %lld", &N, &L);

    S.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    trie.push_back(vector<int>(2, -1));
    term.push_back(0);
    dep.push_back(0);

    for(int i = 0; i < N; i++) {
        int u = 0;
        for(int j = 0; j < S[i].size(); j++) {
            if(trie[u][ S[i][j] - '0' ] == -1) {
                trie[u][ S[i][j] - '0' ] = trie.size();
                trie.push_back(vector<int>(2, -1));
                term.push_back(0);
                dep.push_back(dep[u] + 1);
            }
            u = trie[u][ S[i][j] - '0' ];
        }
        term[u] = 1;
    }

    dfs(0);

    ll Xor = 0;
    for(int i = 0; i < hi.size(); i++) {
        if(hi[i] % 2 == 0) {
            Xor ^= 1;
            continue;
        }
        hi[i]++;

        for(int j = 60; j >= 0; j--) {
            if(hi[i] % (1LL << j) == 0) {
                Xor ^= (1LL << j);
                break;
            }
        }
    }
    if(Xor) printf("Alice");
    else printf("Bob");
}
