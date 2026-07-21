#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<int,int> P;
typedef pair<int,P> PP;
int n;
int ans;
int nn;
int a,b;
vector<int> hai[10000];
int main()
{
    cin>>n;
    for(int m=2;m<100000;m++)
    {
        if(m*(m-1)==2*n)
        {
            nn=m;
            break;
        }
        if(m*(m-1)>2*n)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    a=0;b=1;
    for(int i=1;i<=n;i++)
    {
        hai[a].push_back(i);
        hai[b].push_back(i);
        if(b!=nn-1)
        {
            b++;
        }
        else{
            a++;
            b=a+1;
        }
    }
    cout<<"Yes"<<endl;
    cout<<nn<<endl;
    rep(i,nn)
    {
        cout<<nn-1;
        rep(j,hai[i].size())
        {
            cout<<" "<<hai[i][j];
        }
        cout<<endl;
    }
    return 0;
}
