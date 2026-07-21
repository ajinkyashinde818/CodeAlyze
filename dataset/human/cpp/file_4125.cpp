#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main(void)
{
	long long xs,ys,xt,yt;
	cin >> xs >> ys >> xt >> yt;
	long long n;
	cin >> n;
	long long x[n+2],y[n+2],r[n+2];
	for(int i=1;i<=n;i++)
		cin >> x[i] >> y[i] >> r[i];
	x[0]=xs;
	y[0]=ys;
	r[0]=0;
	x[n+1]=xt;
	y[n+1]=yt;
	r[n+1]=0;

	long double dis[n+2][n+2];
	for(int i=1;i<=n+2;i++)
	{
		for(int j=1;j<=n+2;j++)
		{
			long long disx=x[i-1]-x[j-1];
			long long disy=y[i-1]-y[j-1];
			dis[i-1][j-1]=(sqrt(disx*disx+disy*disy)-r[i-1]-r[j-1]);
			if(dis[i-1][j-1]<0)
				dis[i-1][j-1]=0;
//cout << dis[i-1][j-1] << endl;
		}
	}

	bool search[n+2];
	for(int i=1;i<=n+2;i++)
		search[i-1]=false;
	search[0]=true;
	long double mingo[n+2];
	for(int i=1;i<=n+2;i++)
		mingo[i-1]=10000000010;
	mingo[0]=0;

	int now=1;
	

	//dijkstra
	while(true)
	{
		if(now==n+2)
		{
			break;
		}
		long double nowmin = 10000000010;
		int next=0;
		for(int i=1;i<=n+2;i++)
		{
			if(search[i-1]==true)
				continue;
			mingo[i-1]=min(mingo[i-1],mingo[now-1]+dis[now-1][i-1]);
			if(mingo[i-1]<nowmin)
			{
				next=i;
				nowmin=mingo[i-1];
//cout <<  now << i << "nowmin:" << nowmin << endl;
			}
		}

		now = next;
		search[next-1]=true;
	}

	printf("%.10Lf\n",mingo[n+2-1]);
//	cout << mingo[n+2-1] << endl;
}
