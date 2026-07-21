#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double Softmax(double val) {
    if (val < 0) {
        val = 0;
    }
    return val;
}

double Min(double a, double b) {
    if (a > b) {
        swap(a, b);
    }
    return a;
}

int main() {
    double X_s, Y_s, X_t, Y_t;
    cin >> X_s >> Y_s >> X_t >> Y_t;
    int n;
    cin >> n;
    vector<vector<double>> rounds(n, vector<double> (3));
    for (auto & vec: rounds) {
        cin >> vec[0] >> vec[1] >> vec[2];
    }
    rounds.push_back({X_t, Y_t, 0});
    vector<pair<double, bool>> dist(n + 1); // distance from s to i-th circle
    for (int i = 0; i < n + 1; ++i) {
        dist[i].first = Softmax(sqrt((X_s - rounds[i][0]) * (X_s - rounds[i][0]) + (Y_s - rounds[i][1]) * (Y_s - rounds[i][1])) - rounds[i][2]);
        dist[i].second = false;
    }
    int iter = 0;
    while (iter < n + 1) {
        int index;
        double distance = numeric_limits<int>::max();
        for (int i = 0; i < n + 1; ++i) {
            if (distance > dist[i].first && !dist[i].second) {
                distance = dist[i].first;
                index = i;
            }
        }
        dist[index].second = true;
        for (int i = 0; i < n + 1; ++i) {
            if (!dist[i].second) {
                dist[i].first = Min(dist[i].first, dist[index].first + Softmax(sqrt((rounds[index][0] - rounds[i][0]) * (rounds[index][0] - rounds[i][0])
                                                 + (rounds[index][1] - rounds[i][1]) * (rounds[index][1] - rounds[i][1])) - rounds[i][2] - rounds[index][2]));
            }
        }
        ++iter;
    }
    cout << fixed << setprecision(10) << dist.back().first;
    return 0;
}
