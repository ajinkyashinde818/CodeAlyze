#include <stdio.h>
#include <string.h>

int main()
{
    int m,n,ln=0,flag=0,z=0;
    scanf("%d %d",&m,&n);
    char a[m][52],b[n][52];
    for(int i=0;i<m;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        scanf("%s",b[i]);
    for(int x=0;x<=m-n;x++)
    {int ans=0,k=0;
       begain: while(a[x][ans]==b[z][ans])
        {
            ans++;
            if(b[z][ans]=='\0')
            {
                k=1;z++;
                flag++;
                break;
            }
        }
        if(ans<m-n)
        {
            ans++;
            goto begain;
        }
        if(k==0)
        {flag=0;z=0;}
        if(flag==n)
        {
            ln=1;
            break;
        }

    }
    if(ln==1)
        printf("Yes");
    else
        printf("No");
}
