#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k,p,l=0,q;
	string st1[100],st2[100];
	cin >> n >> m;
	for(i=0; i<n; i++)
		cin >> st1[i];
	for(i=0; i<m; i++)
		cin >> st2[i];
	for(i=0; i<=n-m; i++)
	{
		for(j=0; j<=n-m; j++)
		{
			q=0;
			for(k=0; k<m; k++)
			{
				for(p=0; p<m; p++)
					if(st1[i+k][j+p]!=st2[k][p]) q=1;
			}
			if(q==0) l=1;
		}
	}
	if(l==1) cout <<"Yes";
	else cout << "No";
}
