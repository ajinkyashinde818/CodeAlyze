#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    for(int i=0; i<3; i++)
        scanf("%d",&a[i]);
    sort(a,a+3);
    int n;
    scanf("%d",&n);
    int num=0;
    for(int i=0;i<=n/a[2];i++)
    {
        for(int j=0;j<=(n-i*a[2])/a[1];j++)
        {
            int k=n-i*a[2]-j*a[1];
            if(k%a[0]==0)
                num++;
        }
    }
    printf("%d\n",num);
    return 0;
}
