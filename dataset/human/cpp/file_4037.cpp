#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <boost/functional/hash.hpp>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;


class circle{
    public:
    circle(){
        x=0;y=0;r=0;
    }
    circle(int a,int b, int c){
        x = a; y = b; r = c;
    }
    void print(){
        printf("x: %d,y: %d,r: %d\n", x, y, r);
    }
    int x,y,r;
};
    
double dist(circle c,circle cc){
        double xxx = (double) (cc.x - c.x), yyy = (double) (cc.y-c.y);
        double xx = xxx*xxx, yy = yyy*yyy; 
        double ret = sqrt(xx + yy);
        double radi = (double) c.r + cc.r;
        if(ret <= radi) return 0.0;
        else return ret - radi;
}
template <typename T,typename S> class graph{
    public:
        graph(){
            directed = false;
        }
        graph(bool direct){
            directed = direct;
        }

        void addv(T value){
            if(ns.find(value)==ns.end()){
            int i = v.size();
            vector<pair<int,S> > tem;
            v.push_back(tem);
            ns[value] = i;
            }
        }
        void adde(T v1,T v2,S cost){
            int i = ns[v1], j = ns[v2];
            v[i].push_back(make_pair(j,cost));
        }
        vector<pair<int,S> > operator[](T value){
            return v[ns[value]];
        }
        int size(){
            return v.size();
        }
        bool is_exist(T value){
            return !(ns.find(value) == ns.end());
        }
        bool is_directed(){
            return directed;
        }
        int edge_size(){
            int sum = 0;
            int n = v.size();
            for(int i=0;i<n; i++) sum += v[i].size();
            return directed ? sum : (sum / 2);
        }
        S dijkstra(T a, T b){
            // if error return -2, if there isnt the route from a to b return -1, else return the valid minimum distance.
            int n = v.size();
            if(ns.find(a)==ns.end() || ns.find(b)==ns.end()) return (S) -2;
            int aa = ns[a], bb = ns[b];
            priority_queue<pair<S,int>,vector<pair<S,int> >, greater<pair<S, int> > > q;
            vector<bool> c(n);
            for(int i=0;i<n;i++) c[i] = false;
            q.push(make_pair((S) 0,aa));
            S cost = (S) 0;
            while(!q.empty()){
                cost = q.top().first;
                int curr = q.top().second;
                q.pop();
                if(curr == bb){c[bb] = true; break;}
                if(!c[curr]){
                    c[curr] = true;
                    for(auto i : v[curr]){
                        if(!c[i.first]) q.push(make_pair(i.second + cost, i.first));
                    }
                }
            }
            if(c[bb]) return cost;
            return (S) -1;
        }        
    private:
        vector<vector<pair<int,S> > > v;
        unordered_map<T,int, boost::hash<T>> ns;
        bool directed;
};



int main(){
    graph<int,double> g;
    int xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    circle s(xs,ys,0), t(xt,yt,0);
    vector<circle> v(n+2);
    swap(v[n],s); swap(v[n+1],t);
    g.addv(n); g.addv(n+1);
    for(int i=0;i<n;i++){
        int x,y,r;
        cin >> x >> y >> r;
        circle cir(x,y,r);
        g.addv(i);
        swap(v[i],cir);
    }
    for(int i=0;i<n+2;i++){
        for(int j=i+1;j<n+2;j++){
            g.adde(i,j, dist(v[i],v[j]));
            g.adde(j,i, dist(v[j],v[i]));
        }
    }
    printf("%.9lf\n", g.dijkstra(n,n+1));
    return 0;
}
