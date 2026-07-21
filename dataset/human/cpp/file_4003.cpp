#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;


long long x[1002], y[1002], r[1002];
double edge[1002][1002];
double d[1002];
int checked_count = 0;
bool checked[1002];
int N;

int main(){
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    cin >> N;
    for(int i = 2; i < N + 2; i++){
        cin >> x[i] >> y[i] >> r[i];
    }

    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < N+2; j++){
            edge[i][j] = edge[j][i] = max(0.0, sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) - (r[i] + r[j]));
        }
    }

    for(int i = 0; i < N+2; i++){
        d[i] = 4000000000;
    }

    d[0] = 0;
    checked_count = 1;
    checked[0] = true;
    int prev_node = 0;
    while(checked_count < N+2){
        double min_dist = 4000000000;
        int next_node;
        for(int i = 0; i < N+2; i++){
            d[i] = min(d[i], d[prev_node] + edge[prev_node][i]);
            if((!checked[i]) && d[i] < min_dist){
                next_node = i;
                min_dist = d[i];
            }
        }
        checked[next_node] = true;
        checked_count++;
        prev_node = next_node;
    }
    printf("%.12lf\n", d[1]);
}
