#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long N = 0;
	cin >> N;

	vector<long long> A(N);
	for (auto& a : A)
	{
		cin >> a;
	}

	bool Is0 = false;
	bool Odd = false;

	long long Min = 1000000001;
	long long Max = 0;

	for (auto& a : A)
	{
		if (a == 0)Is0 = true;
		if (a < 0)Odd = !Odd;

		long long n = abs(a);

		Max += n;
		if (n < Min)Min = n;
	}

	if (Odd && !Is0)
	{
		Max -= Min * 2;
	}

	cout << Max;
}
