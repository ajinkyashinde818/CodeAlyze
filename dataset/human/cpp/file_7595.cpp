#include <vector>
#include <iostream>
using namespace std;

int main()
{

	long long N;
	cin >> N;

	vector<long long> list;
	list.reserve(N);

	long long nus = 0, alai =0;


	for (long long i = 0; i < N; i++)
	{
		long long in;
		cin >> in;
		list.push_back(in);

		alai += in;

	}

	nus = list[0];
	alai -= list[0];
	long long ans = abs(nus - alai);

	for (long long i = 1; i < N-1; i++)
	{
		nus += list[i];
		alai -= list[i];
		long long tmp = abs(nus - alai);
		if (ans > tmp)
			ans = tmp;
		
	}

	cout << ans << endl;

	return 0;
}
