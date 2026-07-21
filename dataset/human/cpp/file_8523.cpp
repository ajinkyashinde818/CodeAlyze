#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int first,second;
string n[50];
string m[50];

int main()
{
	cin >> first >> second;
	
	for(int i=0;i<first;i++)
	{
		cin >> n[i];	
	}
	
	for(int i=0;i<second;i++)
	{
		cin >> m[i];	
	}
	int ok = 0;
	for(int i=0;i + (second-1)<first;i++)
	{
		for(int j=0;j + (second-1)<first;j++)
		{
			ok = 0;
			int tmp = i;
			int tmp2 = j;
				for(int k=0;k<second;k++)
				{
					for(int l=0;l<second;l++)
					{
						tmp = i + k;
						tmp2 = j + l;
						if(m[k][l] == n[tmp][tmp2]) ok++;
						else break;
					}
				}
			if(ok == second * second)
			{
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
}
