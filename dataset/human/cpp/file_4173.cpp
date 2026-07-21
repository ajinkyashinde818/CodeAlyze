#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <queue>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;

#define ten(n) ((int)1e##n)
#define COUT cout <<
#define SPACE_COUT << " "  <<
#define COMMA_COUT << ", " <<
#define ENDL << endl;

double distance(tuple<ll, ll, ll> n1, tuple<ll, ll, ll> n2) {
    double x = get<0>(n1) - get<0>(n2);
    double y = get<1>(n1) - get<1>(n2);
    double r = get<2>(n1) + get<2>(n2);
    double dist = sqrt(x * x + y * y) - r;
    return dist > 0 ? dist : 0;
}

class AscendPair {
  public:
    bool operator() (pair<double, int> n1, pair<double, int> n2) {
        return n1.first > n2.first;
    }
};

int
main()
{
    cin.tie(0);
    cout << setprecision(12);
    ios::sync_with_stdio(false);
    
    int N;
    vector<tuple<ll, ll, ll> > nodes;
    ll x, y, r;
    cin >> x >> y;
    nodes.push_back(make_tuple(x, y, 0));
    cin >> x >> y;
    nodes.push_back(make_tuple(x, y, 0));
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> r;
        nodes.push_back(make_tuple(x, y, r));        
    }
    
    vector<double> dijkstra(nodes.size());
    vector<vector<double> >  paths(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        tuple<ll, ll, ll> node = nodes[i];
        vector<double>& path = paths[i];
        path.resize(nodes.size());
        for (int j = 0; j < nodes.size(); ++j) {
            double dist = distance(node, nodes[j]);
            path[j] = dist;
        }
        dijkstra[i] = DBL_MAX;
    }

    set<int> used;
    priority_queue<pair<double, int> , vector<pair<double, int> >, AscendPair > pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        pair<double, int> kv = pq.top(); pq.pop();
        double cost = kv.first;
        int index = kv.second;        
        used.insert(index);

        if (dijkstra[index] < cost) continue;
        dijkstra[index] = cost;
        if (index == 1) break;

        vector<double> path = paths[index];
        for (int i = 0; i < nodes.size(); ++i) { 
            if (used.find(i) != used.end()) continue;
            pq.push(make_pair(cost + path[i], i));
        }        
    }
    cout << dijkstra[1] << endl;

    return 0;
}
