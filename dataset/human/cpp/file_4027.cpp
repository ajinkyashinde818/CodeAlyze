#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;

double dis[1002][1002];
double px[1002], py[1002], r[1002];
double cost[1002];
bool used[1002];

double euclid(int i, int j){
    double square = (px[i] - px[j])*(px[i] - px[j]) + (py[i] - py[j])*(py[i] - py[j]);
    return sqrt(square);
}

void dijkstra(int s, int N){
    cost[s] = 0.0;

    while(true){
        int v = -1;
        for(int u = 0; u < N+2; u++){
            if(!used[u] && (v == -1 || cost[u] < cost[v]))  v = u;
        }
        if(v == -1) break;
        used[v] = true;

        for(int u = 0; u < N+2; u++){
            cost[u] = min(cost[u], cost[v]+dis[v][u]);
        }
    }
}

int main(){
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int N; cin >> N;
    px[0] = xs; py[0] = ys; r[0] = 0.0;
    px[N+1] = xt; py[N+1] = yt; r[N+1] = 0.0;

    for(int i = 1; i <= N; i++){
        double x, y, rr; cin >> x >> y >> rr;
        px[i] = x; py[i] = y; r[i] = rr;
    }

    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < N+2; j++){
            dis[i][j] = max(euclid(i, j) - r[i] - r[j], 0.0);
        }
        used[i] = false;
        cost[i] = 1e9 * 5;
    }

    dijkstra(0, N);
    printf("%.10f", cost[N+1]);

    return 0;
}
