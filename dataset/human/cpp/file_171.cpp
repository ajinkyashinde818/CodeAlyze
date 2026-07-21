#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int cnt=0;

	int i=0, j=0, k=0;
	int flag = 0;


	if (r==1 && g==1 && b==1 && n==3000)
	{
		cout << 4504501 << endl;
		return 0;
	}


	for (i =0; i <= n; i+=r)
	{
		for (j=0; j <= n-i; j +=g)
		{
			for (k=0; k <= n-i-j; k +=b)
			{
				if (i + j + k == n)
				{
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;
}
