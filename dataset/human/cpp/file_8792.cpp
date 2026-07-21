#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	string a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	string b[m];
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	
	for(int i = 0; i < n - m + 1; i++)
	{
		for(int j = 0; j < n - m + 1; j++)
		{
			bool flag = true;
			for(int k = i; k < i + m; k++)
			{
				for(int l = j; l < j + m; l++)
				{
					if(a[k][l] != b[k - i][l - j])
					{
						flag = false;
						break;
					}
				}
			}
			
			if(flag == true)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	
	cout << "No" << endl;
}
