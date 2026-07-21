#include<bits/stdc++.h>
using namespace std;
double d[1003];
long long x[1003],y[1004],r[1004],v[1004];
long long inf =1000000000000000000;
long long int mod=1000000007;
long long int j=mod-2;
long long int modpow (long long int a) {
	long long int res = 1;
	j=mod-2;
	while (j > 0)
		if (j & 1) {
			res = (res * a) % mod;
			--j;
		}
		else {
			a = (a * a) % mod;
			j >>= 1;
		}
	return res %mod;
}
double dist(int l,int e)
{
    double s=x[l]-x[e];
    double q=y[l]-y[e];
    s=s*s+q*q;
    s=sqrt(s);
    return s;
}
int main()
{
   long long int xs,ys,xt,yt;
   cin>>x[0]>>y[0]>>xt>>yt;
   long n;
   cin>>n;
   for(long i=1;i<=n;i++)
   {
       cin>>x[i]>>y[i]>>r[i];
       d[i]=inf;
   }
   d[0]=0;d[n+1]=inf;
   x[n+1]=xt;y[n+1]=yt;n++;
   set<pair< double ,int> >s;
   s.insert(make_pair(0,0));
   while(!s.empty())
   {
       double h=s.begin()->first;
       long f=s.begin()->second;
       v[f]=1;s.erase(s.begin());
      // cout<<f<<" "<<d[f]<<endl;
       if(f==n){  printf("%.12f\n", d[f]);return 0;}
       for(long i=1;i<=n;i++)
       {
           if(v[i]==0)
           {
               double w=dist(f,i);
               double p=r[i]+r[f];
               w=w-p;
               if(w<0)w=0;
               if(d[i]>d[f]+w){s.erase(make_pair(d[i],i));d[i]=d[f]+w;s.insert(make_pair(d[i],i));}

           }

       }
   }

}
