#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
LL N,k,i,j,T;
queue<LL>X;
queue<LL>Y[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(k=1;k<=N*2;k++)
        if(k*(k+1)==2*N)
            break;
    if(k>N*2)
        return cout<<"No"<<endl,0;
    cout<<"Yes"<<endl;
    cout<<k+1<<endl;
    for(i=1;i<=N;i++)
        X.push(i);
    for(i=0;i<=k;i++)
    {
        cout<<2*N/(k+1);
        for(j=0;j<k-i;j++)
        {
            T=X.front();
            X.pop();
            cout<<' '<<T;
            Y[i].push(T);
        }
        for(j=0;j<i;j++)
        {
            T=Y[j].front();
            Y[j].pop();
            cout<<' '<<T;
        }
        cout<<endl;
    }
    return 0;
}
