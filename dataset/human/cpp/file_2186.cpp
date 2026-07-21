#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int minn=1000000000;
        long long sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=abs(a[i]);
            if(a[i]<0) ans++;
            if(abs(a[i])<minn) minn=abs(a[i]);
        }
//        cout<<sum<<endl;
        if(ans%2) sum-=2*minn;
        printf("%lld\n",sum);
    }
}
