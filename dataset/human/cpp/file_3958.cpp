#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include <cstring>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> N;
    vector<long long> x(N + 2);
    vector<long long> y(N + 2);
    vector<long long> r(N + 2);
    vector<vector<double> >distance(N + 2, vector<double>(N + 2));
    x[0] = x1;
    x[1] = x2;
    y[0] = y1;
    y[1] = y2;
    r[0] = r[1] = 0;
    for (int i = 2; i < N + 2; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < N + 2; ++i) {
        for (int j = i; j < N + 2; ++j) {
            if (i == j) {
                distance[i][j] = 0;
            } else {
                double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j];
                distance[j][i] = distance[i][j] = max(0.0, d);
            }
        }
    }
    for (int j = 0; j < N + 2; ++j) {
        for (int i = 0; i < N + 2; ++i) {
            for (int k = i + 1; k < N + 2; ++k) {
                if (distance[i][k] > distance[i][j] + distance[j][k]) {
                    distance[i][k] = distance[k][i] = distance[i][j] + distance[j][k];
                }
            }
        }
    }
    printf("%.10lf\n", distance[0][1]);
    return 0;
}
