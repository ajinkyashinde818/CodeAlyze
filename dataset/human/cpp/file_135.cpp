#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r,g,b;
	int n;
	cin>>r>>g>>b>>n;
	int num=0;
	for(int x=0;x<=n/r;x++)
	   for(int y=0;y<=n/g;y++)
	   {
	   	int z=n-r*x-g*y;
	   	if(z>=0&&z%b==0)num++;
	   }
	   
	cout<<num;
	return 0;
}
