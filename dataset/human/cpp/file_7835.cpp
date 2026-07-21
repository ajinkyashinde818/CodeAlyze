#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	long long sum = 0;
	vector<long long> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	long long tmp = 0;
	long long ans = 2*(*max_element(a.begin(), a.end()));
	for(int i = 0; i < n - 1; i++)
	{
		tmp += a[i];
		
		long long ttmp = sum - 2*tmp > 0 ? sum - 2*tmp : 2*tmp - sum;
		
		if(ans > ttmp)
		{
			ans = ttmp;
		}
	}
	cout << ans << endl;
	return 0;
}
