#include <iostream>
#include <cmath>
using namespace std;
const long long MAXN = 2e5+5;
int main()
{
	long long n,relsum = 0;
	cin >> n;
	long long sl[MAXN];
	for (int i = 0; i < n; i++)
	{
		cin >> sl[i];
	}
	for (int i = 0; i < n; i++)
	{
		relsum += sl[i];
	}
	//cout << relsum;
	long long sumx[n] = {0};
	long long sumy[n] = {0};
	for (int i = 1; i <= n - 1;i++)
	{
		sumx[i] += sumx[i - 1] + sl[i - 1];
		sumy[i] = relsum - sumx[i];
	}

	/*
	for (int i = 1; i < n - 1;i++)
	{
		cout << sumx[i] << "xxx" << sumy[i] << endl;
	}
	*/
	
	long long cha[n - 1] = {0};
	for (int i = 1; i <= n - 1;i++)
	{
		cha[i] = abs((sumx[i])- (sumy[i]));
		
	}
	/*
	for (int i = 1; i < n - 1;i++)
	{
		cout << cha[i] << endl;
	}*/
	
	long long min = cha[1]; 
	for (int i = 1; i <= n - 1;i++)
	{
		if (cha[i] < min)
		min = cha[i];
	}
	cout << min;
}
