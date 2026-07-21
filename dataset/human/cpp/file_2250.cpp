#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
int main()
{
    ll A[100000],b[100000],sum=0;
    int N,count=0,i;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
    }
    for(i=0;i<N;i++)
    {
        if(A[i]<0)
            count++;
    }
    if(count%2==0)
        for(i=0;i<N;i++)
    {
        sum+=abs(A[i]);

    }
       else if(count%2==1)
       {
           for(i=0;i<N;i++)
       {
            b[i]=abs(A[i]);
       }
    sort(b,b+N);
    for(i=1;i<N;i++)
    {
        sum+=b[i];
    }
    sum=sum-b[0];
}
        cout<<sum<<endl;
}
