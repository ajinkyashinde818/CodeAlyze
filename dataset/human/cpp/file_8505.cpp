#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int m, n;; cin >> n >> m;
	vector<vector<char>>x(n,vector<char>(n));
	vector<vector<char>>y(m,vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> x[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> y[i][j];
		}
	}



	for (int i = 0; i <= n - m ; i++) {
		for (int j = 0; j <= n - m ; j++) {
			bool xx = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (x[i + k][j + l] != y[k][l]) {
						xx= false;
					}
				}
			}
			if (xx) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;


	
}
