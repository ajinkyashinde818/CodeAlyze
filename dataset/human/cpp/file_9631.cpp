#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <array>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<int, int> P;

int N, M;
std::string A[51], B[51];

int main()
{
	in >> N >> M;
	rep(i, N) { in >> A[i]; }
	rep(i, M) { in >> B[i]; }

	rep(x, (N - M) + 1)
	{
		rep(y, (N - M) + 1)
		{
			bool same_flag = true;
			for (int i = 0; i < M; ++i)
			{
				for (int j = 0; j < M; ++j)
				{
					if (A[x + i][y + j] != B[i][j])
					{
						same_flag = false;
						break;
					}
				}
				if (same_flag == false)
				{
					break;
				}
			}
			if (same_flag == true)
			{
				out << "Yes" << std::endl;
				return 0;
			}
		}
	}
	out << "No" << std::endl;
	return 0;
	return 0;
}
