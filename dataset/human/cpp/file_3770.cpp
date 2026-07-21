#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <array>
#include <iomanip>


using namespace std;

struct Point {
    long double x;
    long double y;
    long double rad;
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::vector<Point> points;

    auto go = [&]() {
        points.push_back({});
        cin >> points.back().x >> points.back().y;
        points.back().rad = 0;
    };
    go();
    go();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        points.push_back({});
        cin >> points.back().x >> points.back().y >> points.back().rad;
    }
    auto calc = [&](int i, int j) {
        return std::max((long double)0.0, sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y)) - points[i].rad - points[j].rad);
    };

    std::vector<long double> current_distance(n + 2);
    std::vector<bool> used(n + 2, false);
    for (auto& el : current_distance) {
        el = 1e18;
    }
    current_distance[0] = 0;

    for (int i = 0; i < n + 2; i++) {
        int cur_min = 1;
        for (int j = 0; j < n + 2; j++) {
            if (current_distance[j] < current_distance[cur_min] && !used[j]) {
                cur_min = j;
            }
        }
        used[cur_min] = true;
        if (cur_min == 1) {
           break;
        }
        for (int j = 0; j < n + 2; j++) {
            if (!used[j]) {
                current_distance[j] = min(current_distance[j], current_distance[cur_min] + calc(cur_min, j));
            }
        }
    }


    cout << std::setprecision(15) << current_distance[1] << std::endl;;

    return 0;
}
