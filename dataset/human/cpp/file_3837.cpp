#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

template<typename T>
void cout_mat(vector<vector<T> > &mat){
    for(int i=0; i<mat.size(); i++){
        vector<T> vec = mat[i];
        cout_vec(mat[i]);
    }
}

double dijkstra(int s, int g, vector<vector<double > > &path, vector<vector<double> > &distance){
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;

    que.push(make_pair(0., s));
    while((int) que.size()>0){
        int node=que.top().second;
        double dist=que.top().first;
        que.pop();

        if(node==g){
            return dist;
        }

        for(int i=0; (int) i<path[s].size(); i++){
            //cout << path[s][i] << ' ' << dist+path[node][i] << endl;
            if(distance[s][i]>dist+path[node][i]){
                distance[s][i]=dist+path[node][i];
                que.push(make_pair(distance[s][i], i));
            }
        }
    }
}

int main(){
    double x, y, z, w;
    cin >> x >> y >> z >> w;
    int N;
    cin >> N;

    vector<vector<double> > vertex(N+2,vector<double>(3,0));
    vertex[0]={x,y, 0.};
    vertex[N+1]={z, w, 0.};

    for(int i=1; i<=N; i++){
        int x, y, r;
        cin >> vertex[i][0] >> vertex[i][1] >> vertex[i][2];
    }

    vector<vector<double> > path(N+2, vector<double>(N+2, 0));
    for(int i=0; i<N+2; i++){
        for(int j=i; j<N+2; j++){
            double dx = vertex[i][0]-vertex[j][0];
            double dy = vertex[i][1]-vertex[j][1];
            double dr = vertex[i][2]+vertex[j][2];
            path[i][j]=max(0., sqrt(dx*dx+dy*dy)-dr);
            path[j][i]=path[i][j];
        }
    }

    //cout_mat(path);
    vector<vector<double> > distance(N+2,vector<double>(N+2,1.*MOD*MOD));
    cout << setprecision(10) <<dijkstra(0, N+1, path, distance) << endl;

}
