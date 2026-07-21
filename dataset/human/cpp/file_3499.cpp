#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;

void Main()
{
	std::int64_t min = std::numeric_limits<std::int64_t>::max();
	int N;
	std::cin >> N;
	bool isodd = false;
	std::int64_t sum = 0;
	for (auto i : boost::irange(0, N))
	{
		std::int64_t v;
		std::cin >> v;
		if (v < std::int64_t())
		{
			isodd = !isodd;
		}
		sum += std::abs(v);
		min = std::min(min, std::abs(v));
	}
	std::cout << sum - (isodd ? 2 * min : std::int64_t()) << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
