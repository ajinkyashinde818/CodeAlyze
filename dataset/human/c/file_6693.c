#include <stdio.h>
#include <string.h>

int main()
{
    while(1)
    {
        int fre[501] = {0,1},a[10000],b[10000];
        int n,l,ans = 0;
        scanf("%d%d",&n,&l);
        if(n == 0&&l == 0)break;
        for(int i = 0; i < l; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            if(a[i] == 1||b[i] == 1)fre[a[i]] = 1,fre[b[i]] = 1;
        }
        for(int i = 0; i < l; i++)
        {
            if(fre[a[i]] == 1&&fre[b[i]] == 0)ans++,fre[b[i]] = 2;
            if(fre[a[i]] == 0&&fre[b[i]] == 1)ans++,fre[a[i]] = 2;
        }
        for(int i = 0; i < n + 1; i++)
        {
            if(fre[i] == 1)ans++;
        }
        printf("%d\n",ans - 1);
    }

    return 0;
}
