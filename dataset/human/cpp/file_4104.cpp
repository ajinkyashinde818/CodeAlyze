#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

struct Node{
    int x, y, r;
};

double getLen(Node n1, Node n2){
    return max(0.0, sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2)) - n1.r - n2.r);
}

int main(){
    int xs, ys, xt, yt, n;
    cin >> xs >> ys >> xt >> yt >> n;
    vector<Node> nodes(n);
    for(int i=0;i<n;i++){
        int x, y, r;
        cin >> x >> y >> r;
        nodes[i] = {x, y, r};
    }
    nodes.push_back({xt, yt, 0});
    Node s = {xs, ys, 0};
    //TODO
    priority_queue<pair<double, Node*>, vector<pair<double, Node*>>, greater<pair<double, Node*>>> pq;
    pq.push({0, &s});
    set<Node*> visited;
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        double cost = p.first;
        Node* n = p.second;
        if(visited.count(n)){ continue; }
        visited.insert(n);
        if(n == &nodes.back()){
            cout << fixed << setprecision(10) << cost << endl;
            return 0;
        }
        for(uint i=0;i<nodes.size();i++){
            if(n == &nodes[i]){ continue; }
            pq.push({cost + getLen(*n, nodes[i]), &nodes[i]});
        }
    }
    return 0;
}
