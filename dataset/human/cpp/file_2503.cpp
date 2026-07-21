#include <iostream>
#include <cmath>
using namespace std;
typedef int long long l;

int main()
{
	l n;
	cin >> n;
	l sum=0,mi=1000000000,nega=0;
	for(l i=1 ; i<=n ; i++)
	{
		l a;
		cin >> a;
		sum+=abs(a);
		l b=abs(a);
		mi=min(b,mi);
		if(a<0) nega+=1;
	}
	cout << sum-(nega%2)*mi*2;
	return 0;
}
