#include<bits/stdc++.h>
using namespace std;

typedef double lf;
typedef pair<int, int> pii;

lf getDist(pii a, pii b) {
    lf dx = a.first - b.first;
    lf dy = a.second - b.second;
    return sqrt(dx*dx + dy*dy);
}

int Xs, Ys, Xt, Yt, N;
struct Info {
    int x, y, r;
};
Info info[1010];
lf adj[1010][1010];

lf f(Info a, Info b) {
    lf tmp = getDist(pii(a.x, a.y), pii(b.x, b.y));
    if(tmp + 1e-9 < a.r + b.r) return 0;
    else return tmp - (lf)(a.r + b.r);
}

int chk[1010];
lf dist[1010];

void dijkstra() {
    for(int i = 0; i < N + 2; i++) dist[i] = 1e12;
    dist[N] = 0;

    while(1) {
        int mn = 1e12, p = -1;
        for(int i = 0; i < N + 2; i++) {
            if(!chk[i] && mn > dist[i]) {
                mn = dist[i];
                p = i;
            }
        }
        if(p == -1) break;
        chk[p] = 1;

        for(int i = 0; i < N + 2; i++) {
            if(i == p) continue;
            dist[i] = min(dist[i], dist[p] + adj[p][i]);
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &Xs, &Ys, &Xt, &Yt, &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &info[i].x, &info[i].y, &info[i].r);
    }
    info[N] = {Xs, Ys, 0};
    info[N + 1] = {Xt, Yt, 0};

    for(int i = 0; i < N + 2; i++) {
        for(int j = i + 1; j < N + 2; j++) {
            adj[i][j] = f(info[i], info[j]);
            adj[j][i] = adj[i][j];
        }
    }

    dijkstra();

    cout << fixed;
    cout.precision(20);
    cout << dist[N + 1];
}
