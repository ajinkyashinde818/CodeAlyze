#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define mod 1000000007

double kyori(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    double xs, ys, xt, yt;
    int n;
    cin >> xs >> ys >> xt >> yt >> n;
    double x[1001], y[1001], r[1001];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    double minkyori[1001];
    for(int i = 0; i < n; i++){
        minkyori[i] = -1.0;
    }
    priority_queue<pair<double, int> > qu;
    for(int i = 0; i < n; i++){
        qu.push(make_pair(-(max(0.0, kyori(xs, ys, x[i], y[i]) - r[i])), i));
    }
    while(!qu.empty()){
        int nowbaria = (qu.top()).second;
        double nowkyori = -(qu.top()).first;
        qu.pop();
        if(minkyori[nowbaria] != -1.0 && minkyori[nowbaria] < nowkyori) continue;
        minkyori[nowbaria] = nowkyori;
        for(int i = 0; i < n; i++){
            double tmp = max(0.0, kyori(x[nowbaria], y[nowbaria], x[i], y[i]) - (r[nowbaria] + r[i]));
            if(minkyori[i] == -1.0 || minkyori[i] > nowkyori + tmp){
                minkyori[i] = nowkyori + tmp;
                qu.push(make_pair(-nowkyori - tmp, i));
            }
        }
    }
    double ans = kyori(xs, ys, xt, yt);
    for(int i = 0; i < n; i++){
        ans = min(ans, minkyori[i] + max(0.0, kyori(xt, yt, x[i], y[i]) - r[i]));
    }
    printf("%.10f\n", ans);
    return 0;
}
