#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;

int main()
{
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	long long count=0;

	for(int i=0;i<=n/r;i++)
		for(int j=0;j<=n/g;j++)
			if((n-i*r-j*g)%b==0 and n-i*r-j*g>=0)
					count++;
	cout << count << endl;


}
