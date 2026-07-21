#include<bits/stdc++.h>
using namespace std;
int main(){
    long xs,ys,xt,yt;
    cin >> xs>>ys>>xt>>yt;
    int n;
    cin >> n;
    long x[n];
    long y[n];
    long r[n];
    for(int i=0;i<n;i++)cin >> x[i]>>y[i]>>r[i];
    double beem[n+2][n+2];
    beem[0][0] = 0.0;
    beem[n+1][n+1] = 0.0;
    beem[0][n+1] = sqrt((double)((xs-xt)*(xs-xt) + (ys-yt)*(ys-yt)));
    beem[n+1][0] = sqrt((double)((xs-xt)*(xs-xt) + (ys-yt)*(ys-yt)));
    for(int i=1;i<=n;i++){
        beem[0][i] = max(sqrt((double)((x[i-1]-xs)*(x[i-1]-xs)+(y[i-1]-ys)*(y[i-1]-ys))) - r[i-1],0.0);
        beem[n+1][i] = max(0.0,sqrt((double)((x[i-1]-xt)*(x[i-1]-xt)+(y[i-1]-yt)*(y[i-1]-yt)))-r[i-1]);

        beem[i][0] = beem[0][i];
        beem[i][n+1] = beem[n+1][i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                beem[i][j] = 0.0;
            }else{
                beem[i][j] = max(sqrt((double)((x[i-1]-x[j-1])*(x[i-1]-x[j-1])+(y[i-1]-y[j-1])*(y[i-1]-y[j-1]))) - r[i-1]-r[j-1],0.0);
            }
        }
    }
    vector<double>distance(n+2,1.0e+12);

    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=n+1;j++){
    //         printf("%d %d: %lf\n",i,j,beem[i][j]);
    //     }
    // }

    
    priority_queue<pair<double,int> ,vector<pair<double,int> >, greater<pair<double,int> > >que;
    que.push(make_pair(0.0,0));

    while(!que.empty()){
        double dist = que.top().first;
        int now = que.top().second;
        que.pop();

        // cout << now << " "<<dist << endl;
        if(distance[now] > dist){
            distance[now] = dist;
        }else{
            continue;
        }
        // distance[now] = min(dist,distance[now]);

        for(int i=1;i<=n+1;i++){
            if(i!=now && dist + beem[now][i] < distance[i]){
                que.push(make_pair(dist + beem[now][i],i));
            }
        }
    }
    printf("%.10lf\n",distance[n+1]);
    

}
