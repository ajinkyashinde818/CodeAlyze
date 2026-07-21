#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
using namespace std;


long long x[1002];
long long y[1002];
long long r[1002];

double c[1002][1002];
double dists[1002];
bool done[1002];

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dijikstra(int N){
    for(int i = 0; i < N; i++){
        dists[i] = LLONG_MAX;
        done[i] = false;
    }
    dists[0] = 0;
    for(int i = 0; i < N; i++){
        bool updated = false;
        int closest;
        long long min_dist = LLONG_MAX;
        for(int j = 0; j < N; j++){
            if(!done[j] && dists[j] < min_dist){
                closest = j;
                min_dist = dists[j];
                updated = true;
            }
        }
        if(!updated){
            break;
        }
        done[closest] = true;
        for(int j = 0; j < N; j++){
            dists[j] = min(dists[j], dists[closest] + c[closest][j]);
        }
    }
}

int main(){
    int N;
    for(int i = 0; i < 2; i++){
        cin >> x[i] >> y[i];
        r[i] = 0;
    }
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[2 + i] >> y[2 + i] >> r[2 + i];
    }

    for(int i = 0; i < N + 2; i++){
        for(int j = 0; j < N + 2; j++){
            c[i][j] = max(0.0, dist(x[i], y[i], x[j], y[j]) - r[i] - r[j]);
            //printf("%f ", c[i][j]);
        }
        //cout << endl;
    }

    dijikstra(N + 2);
    printf("%.10f\n", dists[1]);
    return 0;
}
