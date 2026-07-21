#include<bits/stdc++.h>
using namespace std;

const int MN = 100010;

int N;
int A[MN], B[MN];
unordered_map<int, int> cnt;

int Xn;
vector<int> X;
map<int, int> dx;

vector<int> adj[MN << 1];
int vis[MN << 1];

void dfs(int u) {
    vis[u] = 1;

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d", &N);

    int x = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        x ^= A[i];
    }
    A[N] = x;
    x = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        x ^= B[i];
    }
    B[N] = x;
    N++;

    for(int i = 0; i < N; i++) cnt[ A[i] ]++;
    for(int i = 0; i < N; i++) {
        cnt[ B[i] ]--;
        if(cnt[ B[i] ] < 0) {
            printf("-1");
            return 0;
        }
    }
    for(int i = 0; i < N; i++) X.push_back(A[i]);
    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    Xn = X.size();
    for(int i = 0; i < Xn; i++) dx[X[i]] = i;
    for(int i = 0; i < N; i++) {
        A[i] = dx[A[i]];
        B[i] = dx[B[i]];
    }

    int t = 0;
    if(A[N - 1] != B[N - 1]) t = 1;
    for(int i = 0; i < N - 1; i++) if(A[i] != B[i] && A[i] == A[N - 1]) t = 1;
    if(t) {
        int d = 0;
        for(int i = 0; i < N; i++) {
            if(i != N - 1 && A[i] == B[i]) {
                d++;
                continue;
            }

            adj[ N + A[i] ].push_back(i);
            adj[ N + B[i] ].push_back(i);
            adj[i].push_back(N + A[i]);
            adj[i].push_back(N + B[i]);
        }
        int ccnt = 0;
        for(int i = 0; i < N; i++) if(!vis[i]) {
            if(i != N - 1 && A[i] == B[i]) continue;
            dfs(i);
            ccnt++;
        }
        printf("%d", N - d + ccnt - 2);
    }
    else {
        int d = 0;
        for(int i = 0; i < N - 1; i++) {
            if(A[i] == B[i]) {
                d++;
                continue;
            }

            adj[ N + A[i] ].push_back(i);
            adj[ N + B[i] ].push_back(i);
            adj[i].push_back(N + A[i]);
            adj[i].push_back(N + B[i]);
        }
        int ccnt = 0;
        for(int i = 0; i < N - 1; i++) if(!vis[i]) {
            if(A[i] == B[i]) continue;
            dfs(i);
            ccnt++;
        }
        printf("%d", N - 1 - d + ccnt);
    }
}
