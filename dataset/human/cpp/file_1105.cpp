#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
#include<boost/dynamic_bitset.hpp>
namespace adaptor = boost::adaptors;
template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

void Main()
{
	int R, G, B, N;
	std::cin >> R >> G >> B >> N;
	int count = 0;
	for (int r = 0; r * R <= N; ++r)
	{
		auto a = r * R;
		for (int g = 0; a + g * G <= N; ++g)
		{
			auto b = g * G;
			auto v = N - (a + b);
			if (v % B == 0)
			{
				++count;
			}
		}
	}
	std::cout << count << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
