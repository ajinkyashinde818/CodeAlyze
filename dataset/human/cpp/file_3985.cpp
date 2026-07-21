///usr/bin/g++ -O2 $0 -o ${0%.cpp} && echo "----------" && ./${0%.cpp}; exit;
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, int> ii; 

const int N = 1010;
int x[N], y[N], n, r[N]; 
double dist[N]; 

int main(int argc, char const *argv[]) {
    scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]); 
    scanf("%d", &n); n += 2; 
    for(int i = 2; i < n; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &r[i]); 
    }

    priority_queue<ii, vector<ii>, greater<ii> > Q; 
    for(int i = 0; i < n; ++i) dist[i] = 1e18;
    dist[0] = 0;
    Q.emplace(0, 0);    

    auto get = [](int i, int j) {
        return max((long double) 0, hypotl(x[i] - x[j], y[i] - y[j]) - (r[i] + r[j])); 
    };

    while(!Q.empty()) {
        auto it = Q.top(); Q.pop(); 
        int u = it.second; double d = it.first;
        if(d > dist[u]) continue; 
        for(int i = 0; i < n; ++i) if(i != u) {
            double L = get(i, u); 
            if(dist[i] > d + L) {
                dist[i] = d + L; 
                Q.emplace(dist[i], i); 
            }
        }
    }

    printf("%.10f\n", dist[1]); 
}
