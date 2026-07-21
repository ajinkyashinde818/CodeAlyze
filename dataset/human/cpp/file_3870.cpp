#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int N;

class Circle {
public:
    Circle(long long int x, long long int y, long long int r) : x(x), y(y), r(r), done(0), min_cost(9e300) {}
    double get_dist(Circle &to) {
        double t = sqrt((x - to.x) * (x - to.x) + (y - to.y) * (y - to.y)) - r - to.r;
        if (t < 0) return 0.0;
        return t;
    }
    double update_min(Circle &from) {
        double cost = get_dist(from) + from.min_cost;
        if (cost < min_cost) min_cost = cost;
        return min_cost;
    }
    double x;
    double y;
    double r;
    bool done;
    double min_cost;
};

double dijk(vector<Circle>& v)
{
    int node = 0;
    while (1) {
        double min_v = 9.1e300;
        int min_idx;
        for (int i=1;i<N+2;i++) {
            if (v[i].done) continue;
            double t = v[i].update_min(v[node]);
            if (t < min_v) {
                min_idx = i;
                min_v = t;
            }
        }
        if (min_idx == 1) {
            return v[1].min_cost;
        }
        v[min_idx].done = true;
        node = min_idx;
    }
}

int main()
{
    long long int xs, ys, xt, yt;
    scanf("%lld %lld %lld %lld", &xs, &ys, &xt, &yt);

    scanf("%d", &N);
    vector<Circle> circles;
    circles.reserve(N+2);
    circles.emplace_back(xs, ys, 0.0);
    circles[0].done = true;
    circles[0].min_cost = 0.0;
    circles.emplace_back(xt, yt, 0.0);
    for (int i=0;i<N;i++) {
        long long int x, y, r;
        scanf("%lld %lld %lld", &x, &y, &r);
        circles.emplace_back(x, y, r);
    }
    printf("%.20f\n", dijk(circles));
}
