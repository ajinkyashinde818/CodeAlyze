#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;cin>>N;

	int x = 0;
	int cnt = 1;
	bool flag = false;
	while (x < N)
	{
		x += cnt++;

		if(x == N)flag = true;
	}

	if (flag)
	{
		cout<<"Yes"<<endl;
		cout<<cnt<<endl;

		vector<vector<int>>GRID(cnt);
		int x = 1;
		for(int i=1;i<cnt;i++)
		{ 
			for (int j = 0; j < i; j++)
			{
				GRID[i].push_back(x);
				GRID[j].push_back(x);
				x++;
			}
		}

		for (int i = 0; i < cnt; i++)
		{
			cout<<cnt-1;
			for (int j = 0; j < cnt - 1; j++)
			{
				cout<<" ";
				cout<<GRID[i][j];
			}
			cout<<endl;
		}
	}
	else {
		cout<<"No"<<endl;
	}
	
	return 0;
}
