#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;
const double INF = 1e15;

struct Node{
    int num;
    double cost;
    bool operator<(const Node& obj)const{
        return cost > obj.cost + EPS;
    }
};

struct Edge{
    int to;
    double distance;
};

struct Circle{
    double x, y, r;
};

vector<Edge> graph[1005];
vector<Circle> circles;
double mini[1005]={0};

double distance(Circle a, Circle b){
    return max(0.,sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) - (a.r+b.r));
}

int main(){
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    graph[0].push_back((Edge){n+1, max(0., sqrt((xt-xs)*(xt-xs)+(yt-ys)*(yt-ys)))});
    for(int i=1;i<=n;++i){
        double x, y, r;
        cin >> x >> y >> r;
        circles.push_back((Circle){x, y, r});
        graph[0].push_back((Edge){i, max(0.,sqrt((x-xs)*(x-xs)+(y-ys)*(y-ys))-r)});
        graph[i].push_back((Edge){n+1, max(0.,sqrt((x-xt)*(x-xt)+(y-yt)*(y-yt))-r)});
    }

    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            graph[i].push_back((Edge){j, distance(circles[i-1], circles[j-1])});
            graph[j].push_back((Edge){i, distance(circles[i-1], circles[j-1])});
        }
    }

    priority_queue<Node> que;
    que.push((Node){0, 0});
    for(int i=0;i<=n+1;++i)mini[i] = INF;
    mini[0] = 0;
    while(!que.empty()){
        Node curr = que.top(); que.pop();
        if(curr.num == n+1){
            printf("%.15lf\n", curr.cost);
            break;
        }
        for(Edge next: graph[curr.num]){
            double newcost = curr.cost + next.distance;
            if(newcost + EPS < mini[next.to]){
                mini[next.to] = newcost;
                que.push((Node){next.to, newcost});
            }
        }
    }

    return 0;
}
