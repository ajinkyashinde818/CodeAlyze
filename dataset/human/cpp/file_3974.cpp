#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

struct Circle { Point center; double radius; };

double distance(const Point p, const Point q)
{
    const auto dx = p.x-q.x, dy = p.y-q.y;
    return sqrt(dx*dx + dy*dy);
}

double distance(const Circle a, const Circle b)
{
    const auto d = distance(a.center, b.center);
    return max(0.0, d - a.radius - b.radius);
}

int main()
{
    cout << setprecision(9) << fixed;

    Point start, finish;
    cin >> start.x >> start.y >> finish.x >> finish.y;

    int N; cin >> N;

    auto circles = vector<Circle>(N);
    for (auto& c : circles)
        cin >> c.center.x >> c.center.y >> c.radius;
    circles.push_back({start, 0});
    circles.push_back({finish, 0});

    const auto s = N, t = N+1;
    N += 2;

    auto distances = vector<double>(N, numeric_limits<double>::infinity());
    distances[s] = 0;

    auto candidates = vector<int>(N);
    iota(begin(candidates), end(candidates), 0);
    while (!candidates.empty())
    {
        const auto compare = [&](const int v, const int w) { return distances[v] < distances[w]; };
        const auto v = *min_element(begin(candidates), end(candidates), compare);
        candidates.erase(remove(begin(candidates), end(candidates), v), end(candidates));

        for (const auto w : candidates)
            distances[w] = min(distances[w], distances[v] + distance(circles[v], circles[w]));
    }

    cout << distances[t] << endl;
}
