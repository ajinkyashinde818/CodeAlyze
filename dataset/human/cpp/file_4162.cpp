#include <bits/stdc++.h>
using namespace std;

long double dis[1005][1005]={};
struct circ
{
    long long x,y,r;
};
circ arr[1005]={};
int n;

vector < long double > s(1006,1e18);
vector < bool > vist;

void dij(int i)
{
    long double kk;
    int j,jj,k;
    priority_queue <pair<long double,int > >ll;
    ll.push({1e17,i});
    s[i]=0;

    while(!ll.empty()){

        jj=ll.top().second;
      //  cout<<jj<<' ';
        ll.pop();
       // cout<<jj<<endl;
        for(j=0;j<n+1;j++)
        {
            k=j;
            kk=dis[jj][j];
            if(s[k]>s[jj]+kk)
            {
                s[k]=s[jj]+kk;
                ll.push({1e17-s[k],k});
            }
        }

    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x1,x2,y1,y2,i,j;

    cin>>x1>>y1>>x2>>y2;
    cin>>n;

    for(i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y>>arr[i].r;
    long double a,b,c,d,e,f;

    a=(x1-x2);
    a=a*a;
    b=(y1-y2);
    b=b*b;
    c=sqrt(a+b);
    d=c;
    d=max(d,(long double)0);
    dis[1001][n]=d;

    for(i=0;i<n;i++)
    {
        dis[i][i]=1e18;
        for(j=i+1;j<n;j++)
        {
            a=(arr[i].x-arr[j].x);
            a=a*a;
            b=(arr[i].y-arr[j].y);
            b=b*b;
            c=sqrt(a+b);
            d=c-(arr[i].r+arr[j].r);
            d=max(d,(long double)0);
            dis[i][j]=d;
            dis[j][i]=d;
        }
        a=(arr[i].x-x2);
        a=a*a;
        b=(arr[i].y-y2);
        b=b*b;
        c=sqrt(a+b);
        d=c-(arr[i].r);
        d=max(d,(long double)0);
        dis[i][n]=d;

        a=(arr[i].x-x1);
        a=a*a;
        b=(arr[i].y-y1);
        b=b*b;
        c=sqrt(a+b);
        d=c-(arr[i].r);
        d=max(d,(long double)0);
        dis[1001][i]=d;
        dis[i][1001]=d;
    }
    dij(1001);
  //  for(i=0;i<1004;i++)for(j=0;j<1005;j++)dp[i][j]=-1;
    cout<<fixed<<setprecision(10)<<s[n]<<' ';




    return 0;
}
