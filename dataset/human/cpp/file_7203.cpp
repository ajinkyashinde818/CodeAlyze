#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
long long ab(long long a)
{
	if (a<0)	return -a;
	return a;
}
int main()
{
	int n;
	long long num1=0,num2=0;
	int t;
	cin >> n;
	vector<long long> ai;
	for(t=0;t<n;t++)
	{
		int a;
		cin >> a;
		ai.push_back(a);
		num2 += ai[t];
	}
	long long min;
	for(t=0;t<n-1;t++)
	{
		num1 += ai[t];
		num2 -= ai[t];
		if(t==0)	min = ab(num2-num1);
		if(ab(num2-num1) < min)	min = ab(num2-num1);
	}
	cout << min << endl;
	return 0;
}
