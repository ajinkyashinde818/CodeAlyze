#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<double,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N;
int X[1010];
int Y[1010];
int R[1010];

double costs[1010][1010];
double d[1010];

double dist(int p1, int p2){
    return sqrt(pow(1.0 * X[p1] - X[p2], 2) + pow(1.0 * Y[p1] - Y[p2], 2));
}

int main(){

    for(int i = 0; i < 2; i++){
        cin >> X[i] >> Y[i];
        R[i] = 0;
    }
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X[i + 2] >> Y[i + 2] >> R[i + 2];
    }
    N += 2;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 円と円の距離を計算する
            double tmp = dist(i, j);
            costs[i][j] = max(0.0, tmp - (R[i] + R[j]));
        }
    }
    for(int i = 0; i < N; i++)
        d[i] = 1e+17;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0.0, 0));
    d[0] = 0;
    while(pq.size()){
        pii p = pq.top(); pq.pop();
        double ccost = p.first;
        int cpos = p.second;
        if(d[cpos] < ccost) continue;
        for(int i = 0; i < N; i++){
            double ncost = ccost + costs[cpos][i];
            int npos = i;
            if(d[npos] > ncost){
                d[npos] = ncost;
                pq.push(pii(ncost, npos));
            }
        }
    }

    printf("%.10f\n", d[1]);

    return 0;
}
