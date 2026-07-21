#include <bits/stdc++.h>
using namespace std;
int a[3],n;
bool cmp(int tmpa,int tmpb)
{
    return tmpa>tmpb;
}
int main()
{
    for(int i=0;i<3;i++)scanf("%d",&a[i]);
    scanf("%d",&n);
    sort(a,a+3);
    int ans=0;
    for(int i=0;i*a[2]<=n;++i)
    {
        for(int j=0;j*a[1]<=n-i*a[2];++j)
        {
            if((n-i*a[2]-j*a[1])%a[0]==0)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}



/*


13 1 4 3000


*/
