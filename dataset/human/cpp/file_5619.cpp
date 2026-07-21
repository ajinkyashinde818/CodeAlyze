#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

int main()
{
	unsigned long long N, R;
	std::cin >> N >> R;

	unsigned long long ans = R;
	if (N < 10) {
		ans = R + 100 * (10 - N);
	}

	std::cout << ans << std::endl;

	return 0;
}
