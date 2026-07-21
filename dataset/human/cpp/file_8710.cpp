#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e2+20;
char a[N][N],b[N][N];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			scanf("%s",a[i]);
		for(int i=0;i<m;i++)
			scanf("%s",b[i]);
		//枚举第一个开始匹配的点 然后暴力匹配即可 
		bool match;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i+m-1>=n||j+m-1>=n) continue;
				
				match=true;
				for(int x=0;x<m;x++)
				{
					for(int y=0;y<m;y++)
					{
						if(a[i+x][j+y]!=b[x][y])
						match=false;
					}
				}
				if(match)
				break;
			}	
			if(match)
			break;
		}	
		if(match)
		puts("Yes");
		else
		puts("No");
		
	}
	return 0;	
}
