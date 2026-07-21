#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long int> a(n);
	vector<long long int> subsum(n);
	long long int suma = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		suma += a[i];
		subsum[i] = suma;
	}
	long long int result = 100000000000;
	if (n == 2)
	{
		cout << abs(a[0] - a[1]) << endl;
		return 0;
	}
	for (int i = 1; i < n - 1; i++)
	{
		long long int temp = abs(subsum[i - 1] - (suma - subsum[i - 1]));
		if (temp < result)
		{
			result = temp;
		}
	}
	cout << result << endl;
	return 0;
}
