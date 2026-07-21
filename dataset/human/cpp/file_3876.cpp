#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

struct position{
    double x, y;
};

struct path{
    int now;
    double distance_all;
    
    bool operator >(const path& another) const{
        return distance_all > another.distance_all;
    }
};

double point_distance(position first, position second){
    return sqrt((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}

int main(){
    position start, goal;
    cin >> start.x >> start.y >> goal.x >> goal.y;
    int N;
    cin >> N;
    pair<position, double> barrier[N + 2];
    for(int i = 0; i < N; i++){
        cin >> barrier[i].first.x >> barrier[i].first.y >> barrier[i].second;
    }
    barrier[N] = {start, 0};
    barrier[N + 1] = {goal, 0};
    priority_queue<path, vector<path>, greater<path>> pathes;
    double distances[N + 2];
    pathes.push({N, 0.0});
    fill(distances, distances + N + 2, 1e18);
    distances[N] = 0.0;
    while(!pathes.empty()){
        path looking = pathes.top();
        pathes.pop();
        if(looking.distance_all > distances[looking.now] + 1e-6){
            continue;
        }
        for(int i = 0; i < N + 2; i++){
            if(looking.distance_all + max(0.0, point_distance(barrier[looking.now].first, barrier[i].first) - barrier[looking.now].second - barrier[i].second) + 1e-6 < distances[i]){
                distances[i] = looking.distance_all + max(0.0, point_distance(barrier[looking.now].first, barrier[i].first) - barrier[looking.now].second - barrier[i].second);
                pathes.push({i, distances[i]});
            }
        }
    }
    cout << fixed << setprecision(10) << distances[N + 1] << endl;
}
