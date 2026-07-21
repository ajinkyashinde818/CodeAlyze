#include <bits/stdc++.h>

struct Edge {
	int to;
	long double dist{1};
};
using EdgeVec = std::vector<Edge>;
using EdgeLists = std::vector<EdgeVec>;

///////////////////
// ダイクストラ法 //
///////////////////

// 負辺を含まないグラフの最短経路アルゴリズム
// Edgeは{to, dist}
template <typename Metric = decltype(Edge::dist)>
std::vector<Metric> dijkstra(const EdgeLists& edges, const int source)
{
	std::vector<Metric> distance(edges.size(), std::numeric_limits<Metric>::max());
	using DistPoint = std::pair<Metric, int>;
	std::priority_queue<DistPoint, std::vector<DistPoint>, std::greater<DistPoint>> updatedQueue;
	distance[source] = 0;
	updatedQueue.push({0, source});
	while (!updatedQueue.empty())
	{
		DistPoint now{updatedQueue.top()};
		updatedQueue.pop();
		if (now.first > distance[now.second]) continue;
		for (const Edge& next: edges[now.second])
			if (now.first + next.dist < distance[next.to])
			{
				distance[next.to] = now.first + next.dist;
				updatedQueue.push({distance[next.to], next.to});
			}
	}
	return std::move(distance);
}

int main()
{
	using Point = std::complex<long double>;
	Point start, goal;
	{
		long double x[2], y[2];
		for (int i{}; i < 2; i++)
			scanf("%Lf%Lf", x + i, y + i);
		start = {x[0], y[0]};
		goal = {x[1], y[1]};
	}
	int N;
	scanf("%d", &N);
	std::vector<Point> points(N);
	std::vector<long double> r(N);
	for (int i{}; i < N; i++)
	{
		long double x, y;
		scanf("%Lf%Lf%Lf", &x, &y, &r[i]);
		points[i] = {x, y};
	}
	// {points, start, goal}
	EdgeLists edges(N + 2);
	for (int i{}; i < N; i++)
		for (int j{}; j < N; j++)
		{
			if (i == j) continue;
			edges[i].push_back({j, std::max<long double>(0, std::abs(points[i] - points[j]) - r[i] - r[j])});
		}
	for (int i{}; i < N; i++)
	{
		edges[N].push_back({i, std::max<long double>(0, std::abs(points[i] - start) - r[i])});
		edges[i].push_back({N + 1, std::max<long double>(0, std::abs(points[i] - goal) - r[i])});
	}
	edges[N].push_back({N + 1, std::max<long double>(0.0, std::abs(start - goal))});
	auto distance{dijkstra<long double>(edges, N)};
	printf("%.10Lf\n", distance[N + 1]);

	return 0;
}
