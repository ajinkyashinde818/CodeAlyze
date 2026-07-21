#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*
typedef long long int int64;
int64 max2(int64 a, int64 b) { return a > b ? a : b; }

int64 max3(int64 a, int64 b, int64 c) { return ((a > b ? a : b) > c ? (a > b ? a : b) : c); }
*/
int main()
{
    int a[110]={0};
    int b[110]={0};
    int i,n;
    int flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        if(i>=2)
        {
            if(a[i-2]==b[i-2]&&a[i-1]==b[i-1]&&a[i]==b[i])flag=1;
        }
    }

    if(flag)printf("Yes");
    else printf("No");
}
