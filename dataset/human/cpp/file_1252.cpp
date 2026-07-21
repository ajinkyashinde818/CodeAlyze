#include <bits/stdc++.h>
int mx[12];
using namespace std;
int main()
{
    int r,g,b,n,i,j;long long s=0;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    if(r>n&&g>n&&b>n)
    {
        printf("0");return 0;
    }
    for(i=0;i<=(n/b);i++)
    {
        for(j=0;j<=(n-(i*b))/g;j++)
        {
            if((n-i*b-j*g)%r==0)
            {
                s++;
            }
        }
    }printf("%I64d",s);
}
