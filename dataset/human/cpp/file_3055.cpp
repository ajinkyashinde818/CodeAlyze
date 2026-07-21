#include<iostream>

using namespace std;

int main()
{
	long n, answer,a[100000], inpu;
	
	cin >> n;
	
	int counter = 0;
	
	answer = 0;
	
	for (long x = 0; x<n ; x++)
	{
		cin >> inpu;
		
		if (inpu < 0)
		{
			counter++;
			a[x] = inpu*-1;
		}
		else a[x] = inpu;
		answer += a[x];
	}
	
	if (counter%2 == 1)
	{
		long lowest = 1000000000;
		for (long x = 0; x<n ; x++)
		{
			if (a[x] < lowest) //lowest == a[x]; (FATAL MISTAKE)
			lowest = a[x];
		}
		answer -= lowest*2;
	}
	
	cout << answer;
	
}
