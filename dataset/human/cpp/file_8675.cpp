#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n,m;
	cin >> n >> m;
	string a[55],b[55];
	for(int i=1;i<=n;i++)
		cin >> a[i-1];
	for(int i=1;i<=m;i++)
		cin >> b[i-1];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			bool ans=true;
			for(int i2=1;i2<=m;i2++)
				for(int  j2=1;j2<=m;j2++)
				{
//cout << i << ":" << j << ":" << i2 << ":" << j2 << endl;
					if(i+i2-1>n or j+j2-1>n)
					{
//cout << "edge" << endl;
						ans=false;
						break;
					}
					if(a[i+i2-1-1][j+j2-1-1]!=b[i2-1][j2-1])
					{
//cout << "not" << endl;
						ans=false;
						break;
					}
				}
			if(ans==true)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}

	cout << "No" << endl;
}
