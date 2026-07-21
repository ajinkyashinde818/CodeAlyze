#include<bits/stdc++.h>
using namespace std;

using lint = long long;

struct point {
    lint x, y;
    point(lint x_ = 0, lint y_ = 0): x(x_), y(y_) { }
    point operator- (const point &p) const {
        return point(x - p.x, y - p.y);
    }
    long double sz() { return sqrt(x * x + y * y); }
    void scan() {
        scanf("%lld%lld", &x, &y);
    }
};

const int N_ = 1050;
int N;
point D[N_]; int R[N_];

long double tb[N_];
bool vis[N_];

int main() {
    D[0].scan();
    D[1].scan();
    scanf("%d", &N); N+=2;
    for(int i=2; i<N; i++) {
        D[i].scan();
        scanf("%d", &R[i]);
    }
    
    // from 0 to 1
    fill(tb, tb+N, 1e18);
    tb[0] = 0;
    for(int rep = 0; rep < N; rep++) {
        int u = -1;
        for(int i = 0; i < N; i++) {
            if(!vis[i] && (u == -1 || tb[u] > tb[i])) u = i;
        }
        assert(u >= 0);
        vis[u] = true;
        for(int v = 0; v < N; v++) if(!vis[v]) {
            long double c = max((long double)0.0, (D[u] - D[v]).sz() - R[u] - R[v]);
            tb[v] = min(tb[v], tb[u] + c);
        }
    }
    
    printf("%.20Lf\n", tb[1]);
    
    
    return 0;
}
