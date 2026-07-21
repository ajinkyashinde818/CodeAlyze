#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<queue>
#include<functional>
#include<set>
#include<complex>
#include<limits>
template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

int main()
{
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1);
	typedef std::complex<double> point;
	double sx, sy, gx, gy;
	std::cin >> sx >> sy >> gx >> gy;
	point start(sx, sy), goal(gx, gy);
	int N;
	std::cin >> N;
	std::vector<std::pair<point, double>> barrier;
	for (int i{};i < N;++i)
	{
		double x, y, r;
		std::cin >> x >> y >> r;
		barrier.emplace_back(point(x, y), r);
	}
	p_queue<std::pair<double, int>> queue;
	int k{};
	for (auto const& b : barrier)
	{
		queue.emplace(std::max(std::sqrt(std::norm(b.first - start)) - b.second, 0.), k++);
	}
	queue.emplace(std::sqrt(std::norm(goal - start)), k);
	std::vector<double> data(N, std::numeric_limits<double>::max());
	while (queue.size())
	{
		auto top = queue.top();
		queue.pop();
		if (top.second == N)
		{
			std::cout << top.first << std::endl;
			return 0;
		}
		if (top.first < data[top.second])
		{
			data[top.second] = top.first;
			auto const& f = barrier[top.second];
			for (int i{};i < N;++i)
			{
				if (i == top.second)
					continue;
				auto const& b = barrier[i];
				queue.emplace(std::max(std::sqrt(std::norm(b.first - f.first)) - b.second - f.second, 0.) + data[top.second], i);
			}
			queue.emplace(std::max(std::sqrt(std::norm(f.first - goal)) - f.second, 0.) + data[top.second], N);
		}
	}
}
