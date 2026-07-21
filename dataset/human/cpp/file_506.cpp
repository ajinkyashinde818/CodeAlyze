#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a , b , c , n;
	
	cin >> a >> b >> c >> n;
	
	int ans = 0;
	
	for(int i = 0 ; a*i<=n ; i++)
	{
		for(int j  = 0 ; b*j<=n ; j++)
		{
			if((n - (a*i+b*j))%c==0 && (n-(a*i+b*j))>=0)
			{
				ans++;
				//cout << a*i << " " << b*j << " " << n-(a*i+b*j) << endl;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
