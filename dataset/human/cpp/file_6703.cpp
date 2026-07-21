#include<iostream>
#include<cmath>
using namespace std;
const double EPS=1e-10;
double wx[100],wy[100],r[100],tx,ty,sx,sy;
int n,m;
main()
{
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)cin>>wx[i]>>wy[i]>>r[i];
		cin>>m;
		for(;m--;)
		{
			cin>>tx>>ty>>sx>>sy;
			bool ok=false;
			for(int i=0;i<n;i++)
			{
				if(hypot(wx[i]-sx,wy[i]-sy)<r[i]+EPS&&
					hypot(wx[i]-tx,wy[i]-ty)<r[i]+EPS)continue;
				double t=((wx[i]-sx)*(tx-sx)+(wy[i]-sy)*(ty-sy))/((tx-sx)*(tx-sx)+(ty-sy)*(ty-sy));
				if(t<0)t=0;
				if(t>1)t=1;
				double x=sx+t*(tx-sx),y=sy+t*(ty-sy);
				double dis=hypot(wx[i]-x,wy[i]-y);
				if(dis<r[i]+EPS)
				{
					ok=true;
					break;
				}
			}
			cout<<(ok?"Safe":"Danger")<<endl;
		}
	}
}
