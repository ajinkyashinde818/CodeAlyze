#include<bits/stdc++.h>
using namespace std;
long long num[34];
void init()
{
    num[0]=1;
    for(int i=1;i<34;i++)num[i]=3*num[i-1];
}
int main()
{
    long long n;
    int ans=0;
    init();
    cin>>n;
    if(n==0){cout<<0<<endl;return 0;}
    n--;
    int i;
    for(i=1;i<34;i++)
    {
        if(n>=2*num[i])
        {
            n-=2*num[i];
            ans+=2;
        }
        else if(n<2*num[i]&&n>=num[i])
        {
            n-=num[i];
            ans++;
            break;
        }
        else break;
    }
    for(int j=i-1;j>=0;j--)
    {
        while(n>=num[j]){n-=num[j];ans++;}
    }
    cout<<ans+1<<endl;
    return 0;
}
