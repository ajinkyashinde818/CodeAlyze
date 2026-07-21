#include<iostream>
using namespace std;
int n,i,k,val,V[2005][2005],j;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=1; i*(i-1)<=2*n; i++)
        k=i;
    if(k*(k-1)!=2*n)
    {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<k<<"\n";
    val=1;
    for(i=1; i<=k; i++)
    {
        cout<<k-1<<" ";
        for(j=1; j<=V[i][0]; j++)
            cout<<V[i][j]<<" ";
        for(j=i+1; j<=k; j++)
        {
            cout<<val<<" ";
            V[j][++V[j][0]]=val;
            val++;
        }
        cout<<"\n";
    }
    return 0;
}
