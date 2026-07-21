#include <iostream>
using namespace std;
      
int main()
{
	int n, m;
	cin >> n >> m;
	char a[n][n], b[m][m];
	for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
			cin >> a[i][j];


	for(int i = 0; i < m; i++)
    	for(int j = 0; j < m; j++)
    		cin >> b[i][j];

	bool check = false;
	for(int i = 0; i <= n-m; i++)
		for(int j = 0; j <= n-m; j++)
		{
	    	for(int k = 0; k < m; k++)
	        	for(int l = 0; l < m; l++)
	        		if( b[k][l] != a[i+k][j+l] )
	        		{
	            		check = true;
	        			goto end;
	        		}
	      	end:{}
	      	if( check == false )
	    	{
	    		cout << "Yes";
				return 0;
			}
	    	check = false;
	    }
	cout << "No";
}
