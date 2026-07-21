#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i, j, k, count=0, r, g, b, n;
	cin >> r >> g >> b >> n;
	int total=n;
	for(i=0; i<=n/r; i+=1)
	{
		for(j=0; j<=n/g; j+=1)
		{
			total=n-i*r-g*j;
			//cout << j << " " << total << endl;
			if(total%b==0 && total>=0)
			{
				count+=1;
				//cout << i << " " << j << " " << total/b << endl;
			}
		}
	}
	cout << count << endl;
}
