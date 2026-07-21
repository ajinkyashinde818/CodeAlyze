#include <iostream>
using namespace std;
int transform(char x)
{
	if(x == '.')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n,m;
	int a[51][51];
	int b[51][51];
	char x;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> x;
			a[i][j] = transform(x);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> x;
			b[i][j] = transform(x);
		}
	}
	for(int i=0;i<=(n-m);i++)
	{
		for(int j=0;j<=(n-m);j++)
		{
			for(int k=0;k<m;k++)
			{
				for(int l=0;l<m;l++)
				{
					if(a[i+k][j+l] != b[k][l])
					{
						goto exit;
					}
				}
			}
			cout << "Yes" << endl;
			return 0;
			exit:
			;
		}
	}
	cout << "No" << endl;
	return 0;
}
