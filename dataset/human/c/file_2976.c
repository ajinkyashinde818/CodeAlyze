#include <stdio.h>

long long int N, A[112345];
long long int sum, tmp;
bool ans_flag = true;

int main(void)
{
	scanf("%lld", &N);
	for (long long int i = 0; i < N; ++i)
	{
		scanf("%lld", &A[i]);
		sum += A[i];
	}

	A[N] = A[0];
	for (long long int i = 0; i < N; ++i)
	{
		A[i] = A[i + 1] - A[i];
	}
	tmp = N*(N + 1) / 2;
	if (sum % tmp == 0)
	{
		tmp = sum / tmp;
		for (long long int i = 0; i < N; ++i)
		{
			A[i] -= tmp, A[i] = -A[i];
			if (A[i] < 0 || A[i] % N != 0)
			{
				ans_flag = false;
				break;
			}
		}
	}
	else
	{
		ans_flag = false;
	}

	if (ans_flag == true)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
