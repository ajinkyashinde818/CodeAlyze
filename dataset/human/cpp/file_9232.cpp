#include <iostream>

int main()
{
	int N, M;

	std::cin >> N >> M;

	char* A = new char[N*N];
	char* B = new char[M*M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			std::cin >> A[j*N + i];
		}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
		{
			std::cin >> B[j*M + i];
		}

	int movi = N - M + 1;
	int movj = movi;

	for (int offi = 0; offi < movi; offi++)
		for (int offj = 0; offj < movj; offj++)
		{
			for (int i = offi; i < offi + M; i++)
				for (int j = offj; j < offj + M; j++)
				{
					if (A[j*N + i] != B[(j-offj)*M + (i-offi)])
					{
						goto NO_MATCH;
					}

				}
		
			std::cout << "Yes" << std::endl;
			return 0;
		NO_MATCH:
			;
		}

	std::cout << "No" << std::endl;
	return 0;
}
