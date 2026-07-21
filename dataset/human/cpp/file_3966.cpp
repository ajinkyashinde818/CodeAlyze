#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
using namespace std;
using P=pair<int,int>;
using PP=pair<P,P>;
using ll=long long;
#define int long long
struct Point{
    int x,y;
};
signed main(){
    Point s,t;
    cin>>s.x>>s.y>>t.x>>t.y;
    int n;
    cin>>n;
    vector<Point> o(n);
    vector<int> r(n);
    for(int i=0;i<n;i++){
        cin>>o[i].x>>o[i].y>>r[i];
    } 
    vector<vector<double>> dis(n+2,vector<double>(n+2));
    for(int i=0;i<n+2;i++){
        dis[i][i]=0;
    }
    for(int i=0;i<n;i++){
        dis[0][i+1]=max((double)0,sqrt((o[i].x-s.x)*(o[i].x-s.x)+(o[i].y-s.y)*(o[i].y-s.y))-r[i]);
        dis[i+1][0]=dis[0][i+1];
    }
    for(int i=0;i<n;i++){
        dis[n+1][i+1]=max((double)0,sqrt((o[i].x-t.x)*(o[i].x-t.x)+(o[i].y-t.y)*(o[i].y-t.y))-r[i]);
        dis[i+1][n+1]=dis[n+1][i+1];
    }
    dis[0][n+1]=sqrt((s.x-t.x)*(s.x-t.x)+(s.y-t.y)*(s.y-t.y));
    dis[n+1][0]=sqrt((s.x-t.x)*(s.x-t.x)+(s.y-t.y)*(s.y-t.y));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            dis[i][j]=max((double)0,sqrt((o[i-1].x-o[j-1].x)*(o[i-1].x-o[j-1].x)+(o[i-1].y-o[j-1].y)*(o[i-1].y-o[j-1].y))-(r[i-1]+r[j-1]));
        }
    }
    using di=pair<double,int>;
    vector<double> ret(n+2,LLONG_MAX);
    priority_queue<di,vector<di>,greater<>> task;
    ret[0]=0;
    task.push(di(0,0));
    while(!task.empty()){
        di p=task.top();
        task.pop();
        if(ret[p.second]<p.first)continue;
        for(int i=0;i<n+2;i++){
            if(ret[i]>p.first+dis[p.second][i]){
                ret[i]=p.first+dis[p.second][i];
                task.push(di(ret[i],i));
            }
        }
    }
    cout<<fixed<<setprecision(16)<<ret[n+1]<<endl;
}
