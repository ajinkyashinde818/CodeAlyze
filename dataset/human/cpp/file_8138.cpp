#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;

int main()
{
	int n;
	LLI snuke = 0, racoon = 0, min;
	cin >> n;
	
	LLI arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		racoon += arr[i];
	}
	
	snuke += arr[0];
	racoon -= arr[0];
	min = abs( snuke - racoon );
	
	for(int i = 1; i < n-1; i++)
	{
		snuke += arr[i];
		racoon -= arr[i];
		if( min > abs( snuke - racoon ) )
			min = abs( snuke - racoon );
	}
	
	cout << min;
}
