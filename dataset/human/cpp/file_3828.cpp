#include<bits/stdc++.h>
using namespace std;

double distance(double x,double y){
    return x*x+y*y;
}

void dijkstra(int s,vector<vector<pair<double,int>>> &edge,vector<double> &d){
    d[s]=0;
    vector<int> used(edge.size(),0);
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> q;
    int v=s;
    for(int loop=0;loop<edge.size()-1;loop++){
        used[v]=true;
        for(int i=0;i<edge[v].size();i++){
            if(!used[(edge[v][i].second)]){
                q.push(make_pair(edge[v][i].first+d[v],edge[v][i].second));
            }
        }
        for(;;){
            auto p=q.top();
            q.pop();
            if(!used[p.second]){
                v=p.second;
                d[v]=p.first;
                break;
            }

        }

    }
    return;

}
int main(){
    int xs,xt,ys,yt;
    cin>>xs>>ys>>xt>>yt;
    int n;
    cin>>n;
    vector<int> x(n),y(n),r(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>r[i];
    vector<vector<pair<double,int>>> edge(n+2);
    for(int i=0;i<n;i++){
        double dis=max(0.0,sqrt(distance(x[i]-xs,y[i]-ys))-r[i]);
        edge[n].push_back(make_pair(dis,i));
        edge[i].push_back(make_pair(dis,n));
        dis=max(0.0,sqrt(distance(x[i]-xt,y[i]-yt))-r[i]);
        edge[n+1].push_back(make_pair(dis,i));
        edge[i].push_back(make_pair(dis,n+1));
    }
    double st=sqrt(distance(xs-xt,ys-yt));
    edge[n].push_back(make_pair(st,n+1));
    edge[n+1].push_back(make_pair(st,n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
         edge[i].push_back(make_pair(max(0.0,sqrt(distance(x[i]-x[j],y[i]-y[j]))-r[i]-r[j]),j));
        }
    }
    vector<double> d(n+2,1e18);
    dijkstra(n,edge,d);
    cout<<setprecision(10)<<fixed<<d[n+1]<<endl;


}
