#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int r,g,b,n,ans=0;
	cin>>r>>g>>b>>n;
	for(int y=0;y<=n;y++)
		for(int z=0;z<=n;z++)
		{
			int req = n - y*b - z*g;
			if(req>=0 && req%r==0)
				ans++; 
		}
	cout<<ans;

    return 0;
}

/*
x = N - y - z;
0<=x<=R
0<=y<=G
0<=z<=B
*/
