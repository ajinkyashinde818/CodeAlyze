module AOJ_Volume0092;

import std.stdio,std.string,std.conv,std.algorithm;

int w[1001][1001];
int main()
{
	string s[1001];
	while(true)
	{
		int n = readln.chomp.to!int;
		if(n == 0) break;

		foreach(i;0..1001)
		{
			foreach(j;0..1001)
			{
				w[i][j] = 0;
			}
		}

		foreach(i;0..n)
		{
			s[i] = readln.chomp;
		}

		foreach(i;0..n)
		{
			foreach(j;0..n)
			{
				if(s[i][j] == '*') w[i][j] = 0;
				else w[i][j] = 1;
			}
		}

		int ans = 0;
		foreach(i;1..n)
		{
			foreach(j;1..n)
			{
				if(s[i][j] == '*')
				{
					w[i][j] = 0;
				}
				else
				{
					w[i][j] = min(w[i-1][j-1],min(w[i-1][j],w[i][j-1])) + 1;
					ans = max(ans,w[i][j]);
				}
			}
		}

		ans.writeln;


	}
	return 0;
}
