#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
long long C,N,x[100050],v[100050],ni[100050],shun[100050],ssum[100050],nsum[100050],ans;
int main ()
{

        while(cin>>N>>C)
        {

                ans=0;
                memset(shun,0,sizeof(shun));
                memset(shun,0,sizeof(ssum));
                memset(nsum,0,sizeof(nsum));
                memset(ni,0,sizeof(ni));
                for(int i=1;i<=N;i++)
                {
                        scanf("%lld %lld",&x[i],&v[i]);
                        ssum[i]=ssum[i-1]+v[i];
                }
                for(int i=1;i<=N;i++)
                {
                        shun[i]=max(shun[i-1],ssum[i]-x[i]);
                }
                for(int i=N;i>=1;i--)
                {
                        nsum[i]=nsum[i+1]+v[i];
                        ni[i]=max(ni[i+1],nsum[i]-(C-x[i]));
                }
                for(int i=0;i<=N;i++)
                {
                       // cout<<shun[i]<<" "<<ni[i]<<endl;
                       // cout<<ssum[i]<<" "<<nsum[i]<<endl;
                }
                for(int i=1;i<=N;i++)
                {
                        ans=max(ans,ssum[i]-2*x[i]+ni[i+1]);
                       // cout<<ssum[i]<<" "<<ni[i-1]<<endl;
                        ans=max(ans,shun[i]);
                }
                for(int i=N;i>=1;i--)
                {
                        ans=max(ans,nsum[i]-2*(C-x[i])+shun[i-1]);
                        ans=max(ans,ni[i]);
                }
               // cout<<ans<<endl;




                cout<<ans<<endl;


        }
}
