#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
using namespace std;

bool IsInside(double x1,double y1,double r1, double x2,double y2) {
    return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= r1*r1);
}

double Distance(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double ComputeDist(double x1, double y1, double r1,
                   double x2, double y2, double r2) {
    
    if (IsInside(x1,y1,r1,x2,y2))
        return 0;
    
    if (IsInside(x2,y2,r2,x1,y1))
        return 0;
    
    
    double d = Distance(x1,y1,x2,y2);
    if (d <= r1+r2)
        return 0;
    else
        return d-r1-r2;
        
    
    
}

bool done[1002];
double min_dist[1002];

double D[1002][1002];
double X[1002];
double Y[1002];
double R[1002];

int main(){
    double xs,ys,xt,yt;
    cin>>xs>>ys>>xt>>yt;
    
    
    int N;
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>X[i]>>Y[i]>>R[i];
    }
    
    X[N+1]=xs;
    Y[N+1]=ys;
    X[N+2]=xt;
    Y[N+2]=yt;
    
    
    for(int i=1;i<=N+2;i++) {
        for(int j=1;j<=N+2;j++) {
            D[i][j]=ComputeDist(X[i],Y[i],R[i],X[j],Y[j],R[j]);
        }
    }
    
    for(int i=1;i<=N+2;i++) {
        done[i]=false;
        min_dist[i]=-1;
    }
    
    
    set<pair<double, int> > verts;
    verts.insert(make_pair(0,N+1));
    
    while(!verts.empty()) {
        
        set<pair<double,int> >::iterator it = verts.begin();
        
        int u = it->second;
        double dist = it->first;
        
        verts.erase(it);
        
        if (done[u])
            continue;
        
        done[u]=true;
        min_dist[u] = dist;
        
        if (u==N+2)
            break;
        
        for(int v=1;v<=N+2;v++) {
            // D[u][v].
            
            if (done[v])
                continue;
            double next_dist = dist + D[u][v];
            verts.insert(make_pair(next_dist, v));
        }
    }
    
    
    printf("%1.11f\n",min_dist[N+2]);
    
    
    
    
    
    
}
