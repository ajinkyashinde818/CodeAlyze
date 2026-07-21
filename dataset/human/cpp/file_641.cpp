#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int r,g,b,n;
string s;

int main() {
	cin >>r>>g>>b>>n;
	int ans = 0;
	for (int i = 0; i <=n/r; i++)
	{
		for (int j = 0; j <= n/g; j++)
		{
			if (((n - i * r - j * g) % b == 0) && n - i * r - j * g >= 0)ans++;
		}
	}
	cout << ans<<endl;


}
